#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW "還魂丹" NOR , ({ "resurrect pill", "pill" }));
        set("long","這是一顆百年難得一見的神丹，連垂死的人吃了幾秒的時間便\n"
                   "能不死且能比常人更長壽。\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
              set("value", 1750);
           set("heal_hp",250);
           set("heal_mp",150);
           set("help_ap",150);
              set("food_remaining", 1);
        }
        setup();
}
