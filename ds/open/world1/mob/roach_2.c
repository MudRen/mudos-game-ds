
inherit NPC;

void create()
{
	set_name("����", ({"cockroach","roach"}) );
	set("long",@LONG
�@���¦⪺����, ���۪o�G���ͻH�M��򪺸}��, �åB���_���R�ʨe��ĲŽ�C
LONG
);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","����"})); //���𳡦�
	set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",2);
	set("str",2);
	set("hp",20);
	setup();
	set_element("ground"); //none,wind,ground,fire,metal,plant,water,
}
