#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIY"�T�������"NOR, ({"gold toad","toad"}) );
  set("long",@LONG
�@���T���}��۪���������Ať���|�ۨӿ��]�C
LONG);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",7);
  set("level",22+random(2));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��","����","�e�}","��}" }) );
  set("verbs", ({"crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
  add_money("coin", 10000);
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say(HIY"�T�������"NOR"���i���O�����������F�C\n");
         destruct(this_object());
         break;
  }
} 
