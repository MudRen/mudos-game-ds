#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�r�D", ({"snake"}) );
  set("long",@LONG
�o�O�@�ب㦳�r�P�@�r���r�D�A�Q�r��i���O�n�����C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1);
  set("level",7);
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
    message_vision("$N���X�r���A�������r�F$n�@�f�I\n"NOR, this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+1));
    return 1;
  }
  return 0;
}
