#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW"九轉還合丹"NOR, ({ "nine around pill","pill" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "是九天玄女集天下之精華，化致而成。\n");
                set("unit","顆");
                    set("value",4000);      
                    set("heal_hp",1000);           
                    set("food_remaining",1);
        }
     setup();
}

