inherit NPC;
void create()
{
	set_name("�»�", ({"black butterfly","butterfly" }) );
	set("long",@LONG
�@���Q���֨����»񽺡A���b�o�̽������R�C
LONG);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "Ĳ��", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
	set("dex",3);
	set("str",3);
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
