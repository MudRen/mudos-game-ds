// dog.c

inherit NPC;

void create()
{
	set_name("����", ({ "dog" }) );
	set("race", "���~");
	set("age", 3);
	set("long", "�@������ż�����������C\n");
	
	set("str", 24);
	set("cor", 26);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set_temp("apply/attack", 10);
	set_temp("armor", 3);

	setup();
}
