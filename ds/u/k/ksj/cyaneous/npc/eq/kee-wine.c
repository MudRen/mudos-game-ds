#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("氣酒", ({ "kee wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","看著這杯氣酒，不斷的冒出泡泡，跟氣水一樣。\n");
                set("unit","杯");
        }
        set("value",80);
        set("heal_mp",20);
        set("water_remaining",3);
        setup();
}

