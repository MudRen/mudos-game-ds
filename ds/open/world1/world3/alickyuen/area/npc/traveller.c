// Npc: /u/a/alickyuen/npc/3.c

inherit NPC;

void create()
{
	set_name("�C��", ({"traveller"}) );
	set("long", "�@�ӱq�~�a�ӳo�̪��C�ȡA�C�ﰲ�鳣���@��諸�Ȧ�ΡC\n");
	set("race", "�H��");
	set("age", 30);
	set("level", 10);
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));

	setup();

}
