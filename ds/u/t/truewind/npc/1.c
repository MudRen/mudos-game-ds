// Npc: /u/t/truewind/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(WHT"白無壽"NOR, ({"White man","man"}) );
	set("long", "風清揚的測試用mob。\n");
	set("race", "人類");
	set("age", 40);
	set("level", 45);
        set("title", "槁木死灰");
	setup();

}
