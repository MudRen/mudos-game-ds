inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(HIR "披薩"NOR, ({ "pizza" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是由一個十分可口的東東，你不知不覺地流下\許\多口水∼∼∼∼\n");
                set("unit", "個");
	     set("value", 200);       
                set("heal_hp",50);
	set("heal_ap", 50);
        	    set("food_remaining", 5);
       }
}