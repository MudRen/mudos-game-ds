#include <ansi.h>
inherit NPC;
void create()
{
set_name(MAG"���p����S"NOR,({"hala moto","moto"}) );
  set("race", "beast");
  set("level",99);
  set("age",1000);
  set("long",@LONG
�ǻ����������A�ëD�C�ӤH����r�����C
LONG
);
  set("limbs", ({ "�j�O", "�T��", "�e��", "���","����"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  setup();
}

int ride_before_action(object me)
{
  message_vision("$N�������I�A�������D�W�F"+this_object()->name()+"���y��C\n",me);
  return 1;
}
int ride_after_action(object me)
{
  message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N�q"+this_object()->name()+"�y��W���F�U�ӡC\n",me);
  return 1;
}

