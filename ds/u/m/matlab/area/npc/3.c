// Npc: /u/m/matlab/npc/3.c

inherit NPC;

void create()
{
	set_name("過路旅者", ({"traveller"}) );
set("long", "臉上略有倦意，但仍給人很有活力的感覺。\n");
	set("race", "人類");
set_skill("unarmed", 20);
set_skill("dodge", 10);
	set("age", 31);
	set("level", 8);

	setup();

}
