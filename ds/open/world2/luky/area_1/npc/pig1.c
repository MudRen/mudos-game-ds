
inherit NPC;

void create()
{
	set_name("����", ({"wild pig","pig"}) );
	set("long", "�o�����ަ��۪����������y���A�ݰ_�Ӥ��Ӧn�S�C\n");
	set("unit","�Y");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 8);
	set("level",15);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
		"���ޫܥ����ĦV�A�A�A�ܧ֪�������{�L�F�C\n",
	}));

	setup();
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
}
