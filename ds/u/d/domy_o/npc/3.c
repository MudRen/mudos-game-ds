// This is a npc made by npcmaker.

inherit NPC;

void create()
{
	set_name( "ＮＰＣ", ({ "npc" }));
	set("long", "這是一個標準的NPC。\n");
	set("age", 1);
	set("level",1);
	set("race", "人類");
	setup();
}
