#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIB"陳年威士忌"NOR, ({ "old-wisgy","wisgy" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","皇宮貴族所飲的飲品，價值不凡，尤其是陳年的，價值更高。\n");
                set("unit","杯");
        }
        set("value",350);
        set("heal_ap",60);
        set("water_remaining",3);
        setup();
}

