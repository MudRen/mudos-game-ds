inherit NPC;

void create()
{
	set_name("�p��", ({"young cattle","cattle"}) );
	set("long",@LONG
�@�Y�p���A�������٤���í�C
LONG);
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",5);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<3;i++)
	{
		meat=new_ob(__DIR__"../obj/beef");
		meat->move(this_object());
	}
	::die();
}