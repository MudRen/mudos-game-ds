#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "�W���~" , ({"single-eye monster","monster"}) );
  set("long",@LONG
�@���u���@���������_���Ǫ��C�t�@���������G�O�Q�������C���Q
���u��A���W���_���o�X���c����C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",70);
  set("attitude", "aggressive");
  set("gender", "����" );
  set("level", 30+random(5));
  set("title", "���~" );
  set("limbs", ({ "�Y��", "����","����","����","�I��" }) );
  set("verbs", ({"bite","claw"}) );
        set("chat_chance",10);
        set("chat_msg",({
        (: random_move() :),
        }) );
  setup();
}