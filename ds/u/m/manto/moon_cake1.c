inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(YEL"菠菜月餅"NOR, ({ "spinage moon cake", "spinage", "cake" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 100);  
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object env,me;
        string type,msg;
        me = this_player();
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if(this_player()->query_temp("do_eat_strmooncake") )
                return notify_fail("你已經吃過菠菜月餅了。\n");
        message_vision("$N大口大口的吃下一個菠菜月餅了。\n",this_player() );
        switch(random(2)){
              case 0: 
              message_vision("$N的身體好像因為菠菜月餅產生了一些變化...\n",this_player() );
              this_player()->add_temp("apply/str",20);
              this_player()->add_temp("do_eat_strmooncake",1);
              call_out("delay",3600,this_player() );
              destruct(this_object());
              break;  
              default: 
              message_vision(HIW"$N大口大口的吃下一個菠菜月餅，突然間好像吃到啥東西...\n"NOR);
               new(__DIR__"ticket")->move(this_player());
              destruct(this_object());
              break;    
        }
return 1;
}

void delay(object me)
{
        if(!me) return;
        tell_object(me,"菠菜月餅帶來的效果好像從你身上消失了。\n" );
        me->add_temp("apply/str",-20);
       me->delete_temp("do_eat_strmooncake");
        destruct(this_object() );
}
