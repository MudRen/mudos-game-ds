#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("清心續骨丹", ({ "foot_pill"}));
        set("long",@LONG
這是一顆只有在清心藥鋪才買得到的丹，此丹散發出一股熱氣。
LONG
        );
        set_weight(5);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "顆");
	        set("eat_msg","$N吃下一顆清心續骨丹。");
	        set("eff_msg",HIG "你感到腿上十分的炙熱，腿上的傷慢慢消失了。" NOR );
	}
	set("value",150);
	set("cure",([
		"right_leg" : 10,
		"left_leg" : 10,
	]));
        setup();
}
