inherit NPC;
void create()
{
	set_name("�ѹ�", ({"rat"}) );
	set("long", "�@�������ë����p�ʪ�, �᭱�٩�ۤ@�����������ڡC\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 2);
	set("level",3);
	setup();

}
