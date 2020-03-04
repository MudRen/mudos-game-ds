#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�H����",({"human-face bogle","bogle"}) );
  set("long",@LONG
�����H�������ǡA����u��|�Bŧ�������C
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",47);
  set("attitude", "aggressive");
  set("level",25+random(4));
  set("limbs", ({ "�y��","����","�e�}","��}"}) ); 
  set("verbs", ({ "bite","claw" }) );     
  set("chat_chance", 10);
  set("chat_msg", ({
      "�H�����R�ۦ��Y�A�Φ������H�������e���n�ۧA�C\n",
     }));                                
  setup();
  add_money("coin",400);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") < 26 && userp(this_player()) )
     this_object()->kill_ob(this_player());
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  switch( random(100) )
  {
    case  0: 
          new(__DIR__"eq/hundred-bogle-necklace")->move(this_object());
          break;
    case  1..30: 
          new(__DIR__"eq/bogle-bead")->move(this_object());
          break;
  }
  ::die();
  return;
}
