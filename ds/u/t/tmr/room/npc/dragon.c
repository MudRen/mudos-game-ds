// dragon.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name( HIC "�������s" NOR, ({ "dragon" }) );
	set("long",
		"�o�O�@���ͪ��b���s���������s�M�e���W������{�{�o��ģ�������~�C\n");

	set("age", 600);
	set("attitude", "friendly");

	set("max_gin", 4000);
	set("max_kee", 6000);
	set("max_sen", 3000);

	set("str", 170);
	set("cor", 150);
	set("cps", 100);
	set("spi", 70);
	set("int", 40);

	set("limbs", ({ "�Y��", "����", "�e��", "���", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

        create_family( HIW "�i�Ʊ��j" NOR ,2, "�ݪ��~" );
	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/armor", 60);

	set("combat_exp", 1000000);
	setup();
}
