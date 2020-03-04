#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"�ѥ���"NOR, ({"jade toad","toad"}) );
  set("long",@LONG
�@�����������p�ɪ�����A�Ⱖ���������a���O�������_�ۡC
LONG
);
  set("race", "beast");
  set("gender", "�۩�");
  set("unit","��");
  set("age",8);
  set("level",23+random(2));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��","����","�e�}","��}" }) );
  set("verbs", ({"crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  switch( random(14) ) 
  {
    case 0:
         say(HIC"�ѥ���"NOR"���i���O�����������F�C\n");
         destruct(this_object());
         break;
  }
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
    case  0..10: new(__DIR__"eq/jade-toad-wrists")->move(this_object());
          break;
  }
  ::die();
  return;
}
