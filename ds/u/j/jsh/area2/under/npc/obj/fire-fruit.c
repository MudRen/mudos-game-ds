#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"火紅果"NOR, ({ "fire fruit","fruit" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "古墓裡的不知名果子，外觀是紅紅的一顆，成熟後掉落在地上。\n");
                set("unit", "顆");
                set("value", 3000);  
                set("food_remaining",5);
                set("heal_hp",500);  
        }
}

