// mind_bug.c

inherit NPC;

void create()
{
	set_name("�[�Q��", ({ "mind bug", "bug" }) );
	set("race", "���~");
	set("age", 3);
	set("long", "�o�O�@���ѭ׹D�H����������Ҥƪ��[�Q�ΡM�|���H����z�C\n");
	
	set("str", 24);
	set("con", 26);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set_temp("apply/attack", 30);
	set_temp("apply/armor", 10);

	setup();
}
