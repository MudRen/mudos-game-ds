#include <ansi.h>
inherit NPC;

void create()
{
  set_name("���謺��",({"west cow","cow"}) );
  set("long","�o�g���������A��������A�@�I�H�ɷ|�ĹL���ˤl�A���H�椧���ߡC\n");
  set("race", "beast");
  set("unit","�Y");
  set("age",6);
	set("title",HIG"�������"NOR);
  set("level",20);
  set("con",query("level")*3/2);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  set_living_name("cow_war");
  carry_object(__DIR__"obj/meat");

}
