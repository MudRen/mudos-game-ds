#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�p��", ({ "dog","mob" }));
	set("long","�@���p�p���p���C\n");

	set("race","���~");
	set("age",3);
	set("level",1);
	set("max_hp",50+random(6));
	set("limbs", ({ "���Y","����","�զ�","�e�}","��}" }) );
	set("verbs", ({ "bite", "claw","crash" }));

	set("chat_chance", 10);
	set("chat_msg",({
  (: command("dog"):),
}));
	setup();
}