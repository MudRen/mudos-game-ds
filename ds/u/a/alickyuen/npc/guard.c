inherit NPC;

void create()
{
	set_name("�p����H", ({ "robot guard","guard" }) );
	set("long", "�� �p�p ���~�ҥͲ�������H,�t�d�u��Naboo�����u�@\n");
	set("race","�����H");
	set("age", 100);
	set("level", 20);
                set("chat_msg", ({
  "�p����H���G�S�ƪ��N�֧֨��C\n",
}));
                set("chat_chance_combat", 14);
                set("chat_msg_combat", ({
 "�p����H���G�ϤF�ϤF�A���M�Q��Naboo�����D�N?!�����a\n",
  "�p����H���G�S�̡̭A��L���F\n"
}));
                set_skill("unarmed", 100);
	setup();

}
