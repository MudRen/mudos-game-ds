
inherit NPC;

void create()
{
	set_name("���s��", ({"wild female pig","pig"}) );
	set("long", "�@�Y�Q�����j���s�ޡA�o�����j���s�ަ��G�ܰQ���~�H�I�J�e���a�L�C\n");
	set("unit","�Y");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 24);
	set("level",28);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	//set_temp("fly",1);
	set("attitude", "aggressive");
	set("chat_chance",1);
	set("chat_msg",({
//		(: this_object(), "random_move" :),
		"���s�ޫܥΤO�����ۧA�ݡC\n",
	}));

	setup();
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
}
