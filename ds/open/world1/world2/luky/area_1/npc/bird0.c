
inherit NPC;

void create()
{
	set_name("�B�ҳ�", ({"bolau bird","bird"}) );
	set("long", "�@���Ŧ⪺�B�ҳ��A�����ۧ��ΦY�C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
