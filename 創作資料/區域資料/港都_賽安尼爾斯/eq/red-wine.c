#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIR"紅酒"NOR, ({ "red wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","紅酒是一般人都喝的起的酒，所以很受到歡迎。\n");
                set("unit","杯");
        }
        set("value",100);
        set("heal_mp",10);
        set("heal_hp",10);
        set("heal_ap",10);
        set("water_remaining",3);
        setup();
}
