#include <path.h>
inherit NPC;

void create()
{
	set_name("巫毒教導師", ({"master"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",55);
	set("age", 40);
	set("long", "一位巫毒教的導師正在教導他的徒弟武藝\n");
        set_skill("blade",100);

	setup();

	add_money("coin",500);
	carry_object(SHENGSAN+"voodoo/eq/leggings")->wear();
}
