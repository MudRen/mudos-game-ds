
inherit NPC;

void create()
{
	set_name("�p����", ({"small butterfly","butterfly","small"}) );
	set("long", "�@���զ⪺�p�����A���b�o�̭��R�C\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "Ĳ��", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",1);
	set("dex",2);
	set("str",1);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
