#include <ansi.h>
//updated by alickyuen on 26/12
inherit NPC;
void create()
{
	set_name( "小動物" , ({ "animal" }) );
	set("long",@long
一隻可愛的小動物。
long
);
	set("age", 60);
	set("level", 1);
 set("race", "野獸");
        set("limbs", ({ "頭部", "腹部","胸部","小爪","背部" }) ); 
        set("verbs", ({ "bite","claw" }) );
	setup();
       set_living_name("reward-war-animal");
}

