#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "�¨��~" , ({"horn monster","monster"}) );
  set("long",@LONG
�o�O�@���Y�W���ۨⰦ�¨��������W���~�A���c���������ۧA�C
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