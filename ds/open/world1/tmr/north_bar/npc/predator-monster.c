#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "�����~" , ({"predator monster","monster"}) );
  set("long",@LONG
�o�O�@�����۽��Y�B�����ι����������~�A��Ӥ������`���o�F�A
���G�ܻ��P�N�i�H��A������b�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("attitude", "aggressive");
  set("level", 25 + random(5));
  set("title", "���~" );
  set("limbs", ({ "���Y","����","����","�e�}","��}" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}
