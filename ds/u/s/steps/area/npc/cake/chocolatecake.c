#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(BLK"黑森林蛋糕"NOR, ({ "chocolate cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"一個散發著巧克力香味的黑森林蛋糕\n"NOR);
                set("unit", "個");
                set("value", 10);
                set("food_remaining",6);
                set("heal_ap",30);
        }
}
