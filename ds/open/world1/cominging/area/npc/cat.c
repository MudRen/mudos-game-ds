inherit NPC;

void create()
{
	set_name("�p��", ({"cat"}) );
	set("long", "�@�������ë����p�ʪ��C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("level",2);
	set("max_hp",30+random(10));
	set("dex",5);
	setup();
}
