inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(HIM"H��agen-Dazs"NOR, ({ "H��agen-Dazs", "dazs" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�J");
                set("value", 10);  
                set("food_remaining",2);
        }
}
