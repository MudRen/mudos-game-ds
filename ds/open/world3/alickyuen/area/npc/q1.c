#include <ansi.h>
inherit NPC;

void create()
{
	set_name("林西", ({"lam sze","lam","sze"}) );
	set("long", "一個終日無所事事的人,給人專稱醉漢。\n");
            set("nickname",RED"醉漢"NOR);
	set("race", "人類");
	set("age", 40);
	set("level", 15);
set("max_hp",1000);
	setup();
carry_object(__DIR__"obj/waterb");
carry_object(__DIR__"wp/staff.c")->wield();
}

