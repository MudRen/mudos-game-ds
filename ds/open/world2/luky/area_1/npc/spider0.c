
inherit NPC;

void create()
{
	set_name("�ǻj��", ({"grey spider","spider"}) );
	set("long", "�@���Ǧ⪺�j�j��A���b�e���j����W��ı�C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" })); //���𳡦�
	set("verbs", ({ "bite","claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",6);
set_temp("apply/hit",-20);      //�z�ƩR���v
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();

}
