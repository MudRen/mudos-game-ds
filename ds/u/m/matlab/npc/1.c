// This is a npc made by npcmaker.

inherit NPC;

void create()
{
set_name( "侍劍老僕", ({ "waiter"}));
set("long" ,"你看到一位和藹可親的長者正向著你微笑，
手中正捧著一個樣式古拙的劍匣，匣內正不斷地透散著
森寒凜冽的劍氣。\n");
set("age", 80);
set("level",5);

	set("race", "人類");
set("gender","男性");
	setup();
}
