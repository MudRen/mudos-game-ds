inherit NPC;

void create()
{
	set_name("����", ({"wild pig","pig"}) );
	set("long", "�o�����ަ��۪����������y���A�ݰ_�Ӥ��Ӧn�S�C\n");
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",7);
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
		"���ޫܥ����ĦV�A�A�A�ܧ֪�������{�L�F�C\n",
	}));
	setup();
}


void die()
{
	object pork;
	int i;
	for(i=0;i<4;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}