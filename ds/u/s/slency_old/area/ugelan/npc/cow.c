// Npc: /u/d/dragonku/npc/1.c

inherit NPC;

void create()
{
	set_name("����", ({"cow"}) );
	set("long", "�O�@�����q���j����\n");
	set("race", "�H��");
	set("age", 3);
	set("level", 3);

	setup();
        carry_object(__DIR__"obj/beef.c");
}
