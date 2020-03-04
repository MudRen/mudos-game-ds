#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"生日禮物"NOR,({"birthday gift","gift","bomb"}));
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("long","這是一生日禮物，不知何時會引爆。\n");
                set("no_give",1);
                set("no_sell",1);
                set("value", 2500);
        }
        setup();
}

void init()
{ 
        object me = this_player();    
        if( me->environment() ) return;
        add_action("do_use","use");
}

int do_use(string arg)
{
        int bomb;
        object me,obj;
        me  = this_player();
        obj = this_object();

        if( arg == "on" )
        {
                if( me->is_busy() ) return notify_fail("你的動作還沒有完成。\n");
                if(obj->query("bomb/time") >1 ) return notify_fail("這定時炸彈已經在使用了。\n");
                tell_object(me,"定時開始。\n");
                me->start_busy(2);
                call_out("add_time",1,me);
                return 1;
        }
        else return 0;
}

int add_time()
{
        int i,bomb,which;
        object me, *ppl;
        me=this_player();
        ppl = all_inventory(environment(me));
        i = this_object()->query("bomb/time");
        which = random(sizeof(ppl));

        if( i > 60 )
        {
                if( !living(ppl[which]) ) which = random(sizeof(ppl));
                if( ppl[which] == me ) which = random(sizeof(ppl));
                message_vision(HIR"忽然！「隆∼隆∼∼」有如地震般的強大威力，朝$N的方向狂捲而去。\n"NOR,ppl[which]);
                message_vision(HIR"只見$N被炸彈轟的灰頭土臉。\n"NOR,ppl[which]);
                ppl[which]->receive_damage("hp",5000+random(101));
                destruct(this_object());
                return 1;
        }
        else {
                bomb = 60 - this_object()->query("bomb/time");

                this_object()->set("bomb/time", i+2 );
                this_object()->set("name",HIC"生日禮物"+HIR+"（"+chinese_number(bomb)+"）"NOR);

                call_out("add_time",1,me);
        }
}
