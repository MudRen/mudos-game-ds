#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(GRN "綠清丹" NOR , ({ "green pill", "pill" }));
        set("long","這是一顆綠色的丹藥，是一顆十分難見的奇丹，什麼都能夠恢復。\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
              set("value", 750);
           set("heal_hp",80);
                 set("heal_mp",80);
           set("heal_ap",80);
              set("food_remaining", 1);
        }
        setup();
}
