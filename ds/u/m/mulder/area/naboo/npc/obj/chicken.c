inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(YEL "燒雞"NOR, ({"fire chicken","chicken"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這一隻燒得好美味的雞，你不知不覺地流下\許\多口水∼∼∼∼\n");
                set("unit", "個");
	set("value", 200);       
                set("heal_hp",15);
	set("heal_ap", 15);
        	set("food_remaining", 5);
       }
}