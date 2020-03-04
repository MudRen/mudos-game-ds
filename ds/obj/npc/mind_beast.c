// mind_beast.c

inherit NPC;

void create()
{
	set_name("�[�Q�~", ({ "mind beast", "beast" }) );
	set("race", "���~");
	set("age", 3);
	set("long", "�o�O�@���ѭ׹D�H����������Ҥƪ��[�Q�~�M�|���H����z�C\n");
	
	set("str", 48);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);

	setup();
}

