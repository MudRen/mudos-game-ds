#include <ansi.h>
inherit NPC;

void create()
{
  set_name("����", ({"ghost worm","worm"}) );
  set("long",@LONG
�@���p����j�p���ΡA���M�Y���h�ʪ����Ͱ��A���W�G���w�ƪ�����
�A�ݰ_�ӴN���O�@�Υհ��A�ר��Y��²���N�O�@�Ӿu�`�Y�C
LONG);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",6);
  set("level",23+random(3));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�I��" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",30);
  set("chat_chance", 5);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}
