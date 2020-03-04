// roc.c

inherit NPC;

void create()
{
	set_name("�_�ߤj�P", ({ "roc" }) );
	set("long",
		"�o�O�@�بӦۥ_�ߤj�A���j���M�e���ʯͻH���_�������i�H��H�j�]�C\n");

	set("race", "���~");
	set("age", 200);

	set("max_gin", 500);
	set("max_kee", 2000);
	set("max_sen", 1100);

	set("str", 80);
	set("cor", 40);
	set("spi", 40);
	set("int", 20);

	set("limbs", ({ "�Y��", "����", "�ͻH", "����" }) );
	set("verbs", ({ "bite", "claw", "poke" }) );

	set_temp("apply/attack", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/dodge", 70);
	set_temp("apply/armor", 30);

	set("combat_exp", 70000);
	setup();
}
