
inherit NPC;

void create()
{
	set_name("����", ({"cricket"}) );
	set("long", "�@���ܥi�R���p����, ���Y�O�����ۡC\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�e�}","��}" })); //���𳡦�
	set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",1);
	set("dex",6);
	set("str",3);
	setup();

}
