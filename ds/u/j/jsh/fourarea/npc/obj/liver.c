#include <ansi.h>
inherit ITEM;


void delay(object me);

void create()
{
        set_name(HIR"火 龍 肝" NOR,({"fire-dragon liver","liver"}) );
        set("long", @LONG
這是火龍的肝臟，有著神奇的功效跟謎點。
LONG
);
        set_weight(10000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",4500);
                set("unit","塊");       
        }
        setup();
}


void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;

        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if(this_object()->query("do_eat") )
                return notify_fail("你吃了。\n");

        message_vision("$N吃下一塊火龍肝。\n",this_player() );
         tell_object(this_player(),HIR "你覺得體內一陣熱血 . . . 力量隨之倍增 ！！\n" NOR);
        this_player()->add_temp("apply/str",5);  
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",40,this_player() );     
        return 1;
}

void delay(object me)
{
        if(!me) return;
          tell_object(me,"火龍肝在你體內散化，體能各方面也漸漸回復。\n" );
        me->add_temp("apply/int",-10);
        me->receive_heal("hp",500);
          tell_object(me,HIR "你覺得好多了。\n"NOR);
       destruct(this_object() );
}

