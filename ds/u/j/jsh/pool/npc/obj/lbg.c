#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"蘿蔔糕"NOR, ({ "loo bou-gow","gow" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "妖精所食的食物。\n");
                set("unit", "片");
                set("value", 5000);  
                set("food_remaining",10);
                set("heal_hp",500);   
                set("heal_ap",500);
                set("heal_mp",500);
        }
}

