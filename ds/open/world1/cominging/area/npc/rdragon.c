#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIB"���s"NOR, ({ "rolling dragon","dragon","mob" }));
	set("long","�ǻ����u���b��誺�@�ɥX�{���Ǫ��C\n");

	set("race","���~");
	set("level", 31+random(5));
	set("age", 50);

	set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
	set("verbs", ({ "bite", "claw","poke" }));

	set_temp("apply/attack", 9);
	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 35);
	set_temp("apply/armor", 12);

	set("combat_exp", 15000);
        setup();
	add_money("silver",2);
}