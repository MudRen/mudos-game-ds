
inherit NPC;

void create()
{
	set_name("�p�]��", ({"small ladybug","ladybug","small"}) );
	set("long", "�i�R�p�����]�ΡA���b�|�B�����A�C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "Ĳ��", })); //���𳡦�
	set("verbs", ({ "bite","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",1);
	set("dex",1);
	set("str",1);
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v

	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
