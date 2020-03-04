#include <ansi.h>
#include <skill.h>

inherit NPC;

void create()
{
    set_name("林中老鬼", ({ "grove ghost", "ghost", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
這是一個死了有幾百年的鬼魂，死後長期被埋在槐樹下，
吸收了槐樹的精髓而成形。
LONG);

	set("title",HIG"無寧莊園"NOR);
    set("age", 60);
	set("level", 40);
    set("race","celestial");
    set("attitude", "aggressive");
    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 50 )	carry_object(__DIR__"obj/blood_meat");

}
