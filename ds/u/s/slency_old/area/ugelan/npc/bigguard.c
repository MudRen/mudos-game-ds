// Npc: /u/d/dragonku/npc/2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"護衛隊"NOR"隊長", ({"bigguard"}) );
	set("long", "身為護衛隊隊長的他看起來是一位很強的人。\n");
	set("race", "人類");
   set("age", 35);
    set("level", 20);

	setup();
carry_object(__DIR__"wq/guardsword")->wield();
}
