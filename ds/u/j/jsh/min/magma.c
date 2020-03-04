#include <ansi.h>
inherit NPC;
void create()
{
  set_name(HIR"炎魔巨人"NOR, ({"magma man","man","magma"}) );
  set("long",@LONG
會不斷的重岩漿裡誕生出來的巨人，攻擊力強大，在岩漿地區
四處的巡邏。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",200);
  set("level",35);  
  set("attitude", "aggressive"); 
  set("evil",2000);
  set("limbs", ({ "頭部", "腹部","胸部","手","腳","背部" }) );
  set("verbs", ({ "bite","claw" }) );  
  set("chat_chance", 13);
  set("chat_msg",({  
  (:random_move():),
  "炎魔巨人的身上不停的留著岩漿....\n",  
        }));
  setup();
  add_money("coin",1000);
} 
void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        //object me=this_player();
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"\n炎魔巨人喝道：哪裡來的小孽種！拿命來！\n"+NOR,ob);
                        ob->receive_damage("hp",300);
                        this_object()->kill_object(environment(ob));
        }
}

