#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(MAG "紫星丹" NOR , ({ "purple star pill", "pill" }));
        set("long","這是一顆泛著紫氣的小丹藥，有著提神的作用，用起法術特別起勁。\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
              set("value", 500);
           set("heal_mp",150);
              set("food_remaining", 1);
        }
        setup();
}
