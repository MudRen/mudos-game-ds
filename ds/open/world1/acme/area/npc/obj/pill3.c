#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIB "碧龍丹" NOR , ({ "blue dragon pill", "pill" }));
        set("long","這是一顆藍色的丹藥，能夠恢復大量的體力。\n");
        set("weight", 200);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
               set("value",300);
                   set("heal_hp",100);
              set("food_remaining", 1);
        }
        setup();
}
