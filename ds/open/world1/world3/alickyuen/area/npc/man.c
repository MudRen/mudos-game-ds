// Npc: /u/a/alickyuen/npc/5.c

inherit NPC;

void create()
{
	set_name("路人", ({"man"}) );
	set("long", "一個路經的行人。\n");
	set("race", "人類");
	set("age", 30);
	set("level", 15);
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));
	setup();
}
