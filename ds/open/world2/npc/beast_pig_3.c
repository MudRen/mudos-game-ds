inherit NPC;
void create()
{
	set_name("�p�s��", ({"small pig","pig"}) );
	set("long", "���ۨ�Ӥp�����p�s�ޡA�٬O�i�R�C\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
	set_temp("apply/hit",-20);      //�z�ƩR���v
	set_temp("apply/dodge",-20);    //�z�ư{���v
	setup();
//	carry_object(__DIR__"../obj/pork");
}

void die()
{
	object pork;
	int i;
	for(i=0;i<2;i++)
	{
	pork=new_ob(__DIR__"../obj/pork");
	pork->move(this_object());
	}
	::die();
}