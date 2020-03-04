// Npc: /u/d/dragonku/npc/1.c

inherit NPC;

void create()
{
	set_name("水牛", ({"cow"}) );
	set("long", "是一隻普通的大水牛\n");
	set("race", "人類");
	set("age", 3);
	set("level", 3);

	setup();
        carry_object(__DIR__"obj/beef.c");
}
