#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIC"元力丸"NOR, ({ "Hp-pill","hp-pill" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一顆匯集各種造血藥材濃縮煉成的，十分昂貴。\n");
                set("unit","顆");
                    set("value",500);          
                     set("heal_hp",200);               
                     set("food_remaining",1);
        }
     setup();
}

