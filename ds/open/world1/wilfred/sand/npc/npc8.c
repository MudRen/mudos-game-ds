#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�Ȥl", ({"scorpion"}) );
  set("long",@LONG
�o�O�@�ب㦳�r�P�@�r���Ȥl�A�Q����i���O�n�����C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1);
  set("level",5);
  set("limbs", ({ "�Y��", "����","�ݳ�","����" }) );
  set("verbs", ({ "bite" }) );
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(3))
  {
    message_vision("$N���X����A���������F$n�@�U�I\n"NOR, this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+1));
    return 1;
  }
  return 0;
}
