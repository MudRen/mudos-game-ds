
inherit NPC;

void create()
{
	set_name("����", ({"snail"}) );
	set("long", "�@���ܥi�R���p����, ���Y�O�����ۡC\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�w��" })); //���𳡦�
	set("verbs", ({ "bite","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 2);
	set("level",2);
	set("dex",1);
	set("str",4);
	setup();

}
