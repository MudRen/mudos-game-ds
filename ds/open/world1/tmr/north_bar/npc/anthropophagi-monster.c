#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "���H�~" , ({"anthropophagi monster","monster"}) );
  set("long",@LONG
�@�Ӵ����O��A�L�ڤW�٥p�ۤ@���ת��Ǫ��A�ݨe���ˤl�A�n��
�n��A�Y�F����..
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("attitude", "aggressive");
  set("level",20+random(5));
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
