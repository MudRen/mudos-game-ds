// Npc: /u/a/alickyuen/npc/3.c

inherit NPC;

void create()
{
	set_name("旅館職員", ({"innkeeper"}) );
	set("long", "他是這間旅館的職員,可以向他詢問一些資料.\n");
	set("race", "人類");
	set("age", 49);
	set("level", 5);

	setup();

}
