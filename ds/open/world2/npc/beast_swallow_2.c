
inherit NPC;

void create()
{
	set_name("�p�P�l", ({"small swallow","swallow","small"}) );
	set("long",@LONG
�@����A���ժ��P�l�A���b�o�̽L�ۡC
LONG);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",2);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
