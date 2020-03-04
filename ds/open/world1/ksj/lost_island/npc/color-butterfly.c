#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"�C"HIM"��"HIG"��"NOR, ({"color butterfly","butterfly"}) );
  set("long",@LONG
�@���C�m�������A�p���ۦb�a����b���O���C
LONG
);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",1);
  set("level",17+random(3));
  set("limbs", ({ "����"}) );
  set("verbs", ({ "crash"}) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
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
  switch( random(10) )
  {
    case  0: new(__DIR__"eq/honey")->move(this_object());
    break;
  }
  ::die();
  return;
}
