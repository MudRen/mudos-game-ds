#include <ansi.h>
//updated by alickyuen on 26/12
inherit NPC;
void create()
{
	set_name( "野生動物" , ({ "wildanimal" }) );
	set("long",@long
一隻野外生活的小動物。
long
);
                set("value", 1000);   
	set("age", 60);
	set("level", 10);
 set("race", "野獸");
        set("limbs", ({ "頭部", "腹部","胸部","小爪","背部" }) ); 
        set("verbs", ({ "bite","claw" }) );
	setup();
}
int accept_object(object who, object ob)
{
        if( ob->id("food") ) {      //飼料
set("creater",leader);
                set_leader(who);
                message("vision", name() + "高興地圍著你叫了起來。\n", environment());
                return 1;
        }
}
