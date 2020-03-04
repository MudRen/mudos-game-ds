#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"�b���T�^"NOR, ({"blade mink","mink"}) );
  set("long",@LONG
�ڻ��I�^�|�y���u�ż����y���A�Q�u�Ť��}���ˤf�N���H¡�X�A�e��
�����S�Q�S���A²�����O�Q��p�M�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",12);
  set("gender", "����" );
  set("level",30+random(3));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����"}) );
  set("verbs", ({"bite","claw"}) );
  add("addition_damage",45);
  add("addition_armor",20);
  set("chat_chance", 25);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    message_vision("$N�Ƭ��@�D�ۭ��A�q$n�������L�A$n�u�P��@�}�@�h�I\n"NOR, me, target);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+1));
    return 1;
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(HIW"�b���T�^"NOR"�Ƭ��@�D�ۭ��A���������F�C\n");
         destruct(this_object());
         break;
  }
} 
