#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"猛虎"NOR, ({ "mightiness tiger","tiger","mob" }));
	set("long","一種山上很兇猛的老虎，已有許\多人被其咬傷害！\n");
	set("race","野獸");
	set("gender","雄性");
	set("level",30+random(4));
	set("age", 200);

	set("limbs", ({ "頭部", "身體","尾巴" }) );
	set("verbs", ({ "bite", "claw" }));

	set_temp("apply/attack", 8);
	set_temp("apply/damage", 15);
	set_temp("apply/dodge", 40);
	set_temp("apply/armor", 25);

	set("combat_exp", 25000);
        setup();
}