#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "老鼠" , ({ "mouse" }) );
	set("level",2);
	set("race","野獸");
	set("age",6);
	set("long","牠是一隻髒兮兮的小黑鼠。\n");
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	setup();
}
