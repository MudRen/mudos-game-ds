
inherit NPC;

void create()
{
	set_name("�p�s��", ({"small pig","pig"}) );
	set("long", "���ۨ�Ӥp�����p�s�ޡA�٬O�i�R�C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",4);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
		"�p�s��[����..]���s�F���n�C\n",
	}));

	setup();
	carry_object(__DIR__"obj/pork");
}
