#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name("子兒的"HIM"替身"NOR, ({"za er's shadow","shadow"}) );
  set("long","子兒的替身。\n");
  set("unit","副");
  set("level",42); 
  set("age",0);
  set("max_hp",12000); 
  set("attitude", "aggressive");
  set_temp("float",1); 
  set_skill("bagi_fist",100);
  map_skill("unarmed","bagi_fist");
                set("chat_chance_combat", 80);
                set("chat_msg_combat", ({
                         (:command("exert bagi_fist"):),
                         (:command("exert bagi_fist"):),
                           (:command("wield fist"):),
                           (:command("exert bagi_fist"):),
                                }) );


  setup();  
  carry_object("/open/world1/wilfred/sand/npc/wp/wp1")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return; 
  if(userp(this_player()) ) this_object()->kill_ob(this_player());
  if( this_player()->query("orochi-enemy") ) this_object()->kill_ob(this_player());
}

void die()
{
  message_vision(HIY"\n$N被打散掉。\n"NOR,this_object());
  destruct(this_object());
  ::die();
  return;
}


        

