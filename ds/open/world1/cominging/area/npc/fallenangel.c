#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�Z����", ({ "fallen angel", "angel","mob" }));
	set("long","�@�Ӧb�a���������C\n");

	set("race","�H��");
	set("age",30+random(30));
	set("level",17);

	set("evil", 199);
	set("chat_chance", 10);
	set("chat_msg",({
  (: command("angry"):),
}));
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	set_temp("apply/dodge", 65);
	set_temp("apply/armor", 10);

	setup();
}