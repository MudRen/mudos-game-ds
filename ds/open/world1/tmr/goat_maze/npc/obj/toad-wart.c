#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "蟾蜍疣" , ({ "toad wart", "wart" }));
        set("long",@LONG
這是一粒從蟾蜍王身上取下來的疣，包覆著一沱惡心的毒汁，不知
吃在嘴裡會是怎樣滋味。
LONG
        );
        set("weight",50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "粒");
        set("value",1);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if( ob->query("do_eat") )
                return notify_fail("你已經含在嘴裡了。\n");
        if(me->query_temp("toad_wart_used") )
                return notify_fail("你嘴裡正含著東西，不能再塞東西進去了。\n");
        if( me->is_fighting() ) me->start_busy(2);
         message_vision(CYN "$N拿出了一粒蟾蜍疣，含在嘴裡不停地吸吮裡頭的毒汁...\n" NOR,me);

        if(!ob->query("toad_wart_used") && !me->query_temp("toad_wart_used") )
        {
                message_vision( HBK "$N臉上頓時被黑氣籠罩，但卻是越見精神健旺，毫無病態！！\n" NOR,me);
                me->add_temp("apply/int", 2);
                me->add_temp("apply/con", 2);
                me->set_temp("toad_wart_used",1);
                ob->set("toad_wart_used",1);
                ob->set("do_eat",1);
                ob->set("no_drop",1);
                ob->set("no_sac",1);
                ob->set("no_give",1);
                ob->set("no_sell",1);
                call_out("delay", 600,me);     //附加屬性維持時間
        }
        return 1;
}

void delay(object me)
{
        if(!me) return;
        message_vision(CYN"$N咕嚕一聲，似乎吞下了什麼東西....\n" NOR,me);
        me->add_temp("apply/int",-2);
        me->add_temp("apply/con",-2);
        me->delete_temp("toad_wart_used");
        destruct(this_object());
}

