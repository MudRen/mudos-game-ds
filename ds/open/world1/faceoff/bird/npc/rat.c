
inherit NPC;

void create()
{
	set_name("�ѹ�", ({"rat"}) );
	set("long", "�@�������ë����p�ʪ�, �᭱�٩�ۤ@�����������ڡC\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 2);
	set("level",3);
	set("dex",9);
	set("con",10);
	setup();

}
