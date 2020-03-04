#include <ansi.h> 
inherit NPC;    

void create()
{
  set_name("�l�઺"HIG"����"NOR, ({"za er's shadow","shadow"}) );
  set("long","�l�઺�����C\n");
  set("unit","��");
  set("level",42); 
  set("age",0);
  set("max_hp",12000);
  set_temp("float",1); 
  set_skill("star-sword",100);
  set_skill("fogseven",100); 
  set_skill("force",100);
  map_skill("sword","star-sword");
  set_skill("moon_force",100);
 set("chat_chance_combat", 100);
  set("chat_msg_combat", ({  
    (: command("exert star-sword") :), 
    (: command("exert star-sword tian") :), 
    (: command("exert star-sword penuma-sword") :), 
         (: command("exert fogseven") :), 

  (: command("do wield sword,exert star-sword tian") :),
  (: command("do wield sword,exert star-sword penuma-sword") :),
  (: command("do wield sword,exert moon_force long-arc"):),
  (: command("exert moon_force recover"):),
  (: command("do wield sword,exert star-sword tian") :),
  (: command("do wield sword,exert star-sword nine") :),
  (: command("do wield sword,exert star-sword penuma-sword") :),
  (: command("do wield sword,exert star-sword tian") :),
         }) );
        
  setup();  
  carry_object("/open/world1/wp/th_sword")->wield();
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
  message_vision(HIY"\n$N�Q�������C\n"NOR,this_object());
  destruct(this_object());
  ::die();
  return;
}

