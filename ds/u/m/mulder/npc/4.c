// Npc: /u/m/mulder/npc/4.c

inherit NPC;

void create()
{
	set_name("木人", ({"abc"}) );
	set("long", "測試中\n");
	set("race", "人類");
	set("age", 20);
	set("level", 999);

	setup();

}
