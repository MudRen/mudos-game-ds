
inherit NPC;

void create()
{
	set_name("�F�l", ({"dove"}) );
	set("long", "�@���զ⪺�p�F�l�A���b�o�̭����C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 2);
	set("level",1);
	set("dex",1);
	set("str",1);
	set("con",1);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set("max_hp",30);
	set("evil",-10);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
