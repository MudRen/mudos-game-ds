#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "�ߵ��~" , ({"hypha monster","monster"}) );
  set("long",@LONG
�o�O�@�������ܺ��C���ߵ������~�A���o�X�D�`
���ߪ�����A���p�G�Ѫ�����C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("attitude", "aggressive");
  set("level", 25 + random(5));
  set("title", "���~" );
  set("limbs", ({ "����","�Y��","�I��", "�e��", "�e�}","��}" }) );
  set("verbs", ({ "bite", "claw" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}
