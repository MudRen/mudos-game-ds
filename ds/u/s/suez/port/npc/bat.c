inherit NPC;
void create()
{
	set_name("����", ({"bat"}) );
	set("long", "�����A�ѹ����Ť����H���C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�ͻH", "�}"})); //���𳡦�
	set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",3);
	set("dex",12);
	set("con",5);
	setup();
}