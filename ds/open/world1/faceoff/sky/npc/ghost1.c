#include <ansi.h>
inherit NPC;
void create()
{
 set_name(MAG"冥衛"NOR,({"guard"}));
 set("long",@LONG
這是在十萬大山封印群獸時攻打神殿陣亡的神獸化成的魂魄，
在這裡永永遠遠的護衛著未經允許進入神殿的侵入者....
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"塵因階級"NOR);
 set("evil",-10);
 set("gender","男性");
 set("level",20);
set("str",100);
set("con",200);
 set_skill("unarmed", 100);
 set("chat_chance",30);
 set("chat_msg", ({"冥衛陰陰的朝你看了一眼.....\n", 
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
                        message_vision( "冥衛對$N作了個歡迎的手勢。\n",me);
           }
           else
           {
                 message_vision( "冥衛陰陰看著$N....。\n",me);
                         command("kill "+me->query("id"));
            }
                 }
}



