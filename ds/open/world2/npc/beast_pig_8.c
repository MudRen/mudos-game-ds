inherit NPC;
void create()
{
	set_name("����", ({"female pig","pig"}) );
	set("long",@LONG
�@�Y�ιʹʪ��j���ޡA���b�a�W���O�ΡC
LONG);
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 5);
	set("level",8);
	setup();
//	carry_object(__DIR__"../obj/pork");
}

void die()
{
	object pork;
	int i;
	for(i=0;i<6;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}