#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIY"啤酒"NOR, ({ "beer" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一大杯啤酒，可以讓人感到清涼。\n");
                set("unit","杯");
        }
        set("value",100);
        this_player()->add("talk_point",10); 
        set("water_remaining",1);
        setup();
}

