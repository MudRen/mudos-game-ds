
inherit NPC;

void create()
{
	set_name("�p����", ({"small cockroach","cockroach","roach"}) );
	set("long",@LONG
�@���@�ئ⪺�p����, ���b�a�W���Ӫ��h�C
LONG
);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","����"})); //���𳡦�
	set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",1);
	set("str",1);
	set("hp",5);
	setup();
	set_element("ground"); //none,wind,ground,fire,metal,plant,water,
}
