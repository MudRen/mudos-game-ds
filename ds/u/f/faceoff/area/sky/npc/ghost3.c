#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIR"萬滅靈蠱"NOR,({"guard"}));
 set("long",@LONG
據說這是十萬大山創始之初即潛伏再十萬大山的靈蠱群，
而如今他在天界得到正位，守護著神殿...
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"混沌階級"NOR);
 set("evil",-10);
 set("gender","男性");
 set("level",40);
set("str",200);
set("con",200);
 set_skill("unarmed", 100);
 set("chat_chance",30);
 set("chat_msg", ({"萬滅靈蠱四周的空間忽然模糊了起來....\n", 
        }) );
 setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob,object who)
{
      object me;
      me = this_player();
        if( !ob || environment(ob) != environment() ) return;
        {
             if(me->query_temp("bless") == 1)
           {
                        message_vision( "萬滅靈蠱攻擊$N時，$N身上的綠光焚燒了萬滅靈蠱的觸手...!!\n",me);
           }
           else
           {
                    message_vision( "萬滅靈蠱對著$N伸出了觸手......。\n",me);
                        command("kill "+me->query("id"));
            }
                 }
}



