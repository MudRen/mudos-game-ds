inherit NPC;

void create()
{
	set_name("�³�", ({"sparrow"}) );
	set("long", "�@���F�F�F�s���p�ʪ��C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 3);
	set("max_hp",50);
	set("level",3);
	set("dex",3);
	setup();
}