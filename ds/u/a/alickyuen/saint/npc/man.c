// Npc: /u/a/alickyuen/npc/5.c

inherit NPC;

void create()
{
	set_name("���H", ({"man"}) );
	set("long", "�@�Ӹ��g����H�C\n");
	set("race", "�H��");
	set("age", 30);
	set("level", 15);
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));
	setup();
}
