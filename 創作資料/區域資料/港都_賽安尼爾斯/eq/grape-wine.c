#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(MAG"葡萄酒"NOR, ({ "grape wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","釀了好幾冬的葡萄酒，對於造血，有很大的功\用。\n");
                set("unit","杯");
        }
        set("value",200);
        set("heal_hp",30);
        set("water_remaining",3);
        setup();
}
