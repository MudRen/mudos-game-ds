
inherit NPC;

void create()
{
	set_name("��֫C��", ({"green frog","frog"}) );
	set("long", "�@����⪺�p�C��A���b�o�̸��Ӹ��h���C\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�I��", "��L", "�{�l" })); //���𳡦�
	set("verbs", ({ "crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
	set_temp("apply/hit",-20);      //�z�ƩR���v
	set_temp("apply/dodge",-20);    //�z�ư{���v
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		//(: this_object(), "random_move" :),
		"�C��.��..��..���s�F���n�C\n",
	}));

	setup();
//	carry_object(__DIR__"obj/pork");
}
