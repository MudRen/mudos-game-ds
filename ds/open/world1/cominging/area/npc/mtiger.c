#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"�r��"NOR, ({ "mightiness tiger","tiger","mob" }));
	set("long","�@�ؤs�W�ܥ��r���Ѫ�A�w���\\�h�H�Q��r�ˮ`�I\n");
	set("race","���~");
	set("gender","����");
	set("level",30+random(4));
	set("age", 200);

	set("limbs", ({ "�Y��", "����","����" }) );
	set("verbs", ({ "bite", "claw" }));

	set_temp("apply/attack", 8);
	set_temp("apply/damage", 15);
	set_temp("apply/dodge", 40);
	set_temp("apply/armor", 25);

	set("combat_exp", 25000);
        setup();
}