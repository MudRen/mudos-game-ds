inherit NPC;

void create()
{
	set_name("����", ({"buffalo"}) );
	set("long",@LONG
�@�Y�Q�����j�������A�Y�W���ۤ@�ﱲ���������C
LONG);
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof","horn" })); //�������A��hoof��crash�rbite��claw��poke
	set("age",7);
	set("level",14);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<10;i++)
	{
		meat=new_ob(__DIR__"../obj/beef");
		meat->move(this_object());
	}
	::die();
}