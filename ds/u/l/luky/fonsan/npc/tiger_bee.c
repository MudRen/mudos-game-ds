
inherit NPC;

void create()
{
	set_name("���Y��", ({"tiger bee","bee"}) );
	set("long", "�@�����r�����Y��, ���ƨg����������I�J�e�a�L���ͪ��C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�ͻH", "����" })); //���𳡦�
	set("verbs", ({ "bite","poke"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
	set("dex",7);
	set("str",5);
	set("attitude", "aggressive");
	setup();

}

void init()
{
 ::init();
 if(userp(this_player()))
 this_object()->set_leader(this_player());	
}