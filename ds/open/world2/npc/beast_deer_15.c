inherit NPC;

void create()
{
	set_name("�է���", ({"white-tail deer","deer"}) );
	set("long",@LONG
�@�Y���o�@�����է����A�������ӡA���ժ����ڤW�٪����F�Q��C
LONG);
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof","tail","horn" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 7);
	set("level",15);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<5;i++)
	{
		meat=new_ob(__DIR__"../obj/deermeat");
		meat->move(this_object());
	}
	::die();
}