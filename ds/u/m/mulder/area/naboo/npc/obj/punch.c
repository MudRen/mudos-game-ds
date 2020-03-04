#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIC"雜果賓治"NOR, ({ "fruit punch","punch" }) );
        set_weight(400);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "這是一杯老少咸宜的飲品，喝(drink)了可以解渴補充體力。\n");
      		set("unit", "杯");
		set("drink_msg","$N拿起一杯$n，咕嚕咕嚕地喝了幾口。\n");
		set("finish_drink_msg","$N將餘下的$n喝光了。\n");
     	}
     	set("value", 50);
        set("heal_ap",15);
        set("heal_mp",14);
	set("water_remaining", 4);
	setup();
}
