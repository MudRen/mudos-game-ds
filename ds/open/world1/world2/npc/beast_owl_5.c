
inherit NPC;

void create()
{
	set_name("���Y�N", ({"owl"}) );
	set("long",@LONG
�@�������C���j�j���զ���Y�N�A�e���G�����w��A����ӡC
LONG);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",5);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v

	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}