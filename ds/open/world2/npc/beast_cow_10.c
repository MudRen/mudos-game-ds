inherit NPC;

void create()
{
	set_name("����", ({"cow"}) );
	set("long",@LONG
�@�Y�髬�e�j�������A���b���ʧ��ڻ��a�ǡC
LONG);
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age",5);
	set("level",10);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<7;i++)
	{
		meat=new_ob(__DIR__"../obj/beef");
		meat->move(this_object());
	}
	::die();
}