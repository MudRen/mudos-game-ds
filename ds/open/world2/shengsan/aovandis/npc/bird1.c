
inherit NPC;

void create()
{
	set_name("�p�P�l", ({"small swallow","swallow","small"}) );
	set("long", "�@����A���ժ��P�l�A���b�o�̽L�ۡC\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",2);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v

	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
