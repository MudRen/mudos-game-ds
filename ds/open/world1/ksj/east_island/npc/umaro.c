#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"���k"NOR, ({"umaro"}));
  set("long",@LONG
���ΰ��j�A���o���V�V�����ǡA���������F�������դ�A�O�j�L��A
�k�n���s���H�����|�J���e�A�ڻ��e�|�޵o�ɭ����C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",50);
  set("gender", "����" );
  set("level",27+random(4));
  set("limbs", ({ "�Y��", "����","����","�e�}","��}"}));
  set("verbs", ({"bite","claw"}));
  add("addition_damage",15+random(5));
  setup();
  carry_object(__DIR__"eq/ice-crystal");
}
