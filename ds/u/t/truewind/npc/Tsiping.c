// Npc: /u/t/truewind/npc/1.c

inherit NPC;

void create()
{
	set_name("�Ӥl��", ({"tsiping"}) );
	set("long", "�Ӥl���O�@�W���L�ؤs���ȫȡC\n");
	set("race", "�H��");
	set("age", 20);
	set("level", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
             "�Ӥl�����D�G�Ӧ��@�C�A�誾�����G�M�W����ǡC\n",
             "�Ӥl����ۻ��誺�ѪšA�g�Ī��o�_�b�ӡC\n",
        }));

	setup();

}
