#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIB "魔星七彩戒"NOR ,({ "devil-ring","ring" }) );
        set("long","這是一只會施放迷煙的戒指，十分亮麗。\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "jade");
        set("unit","只");
        set("value",700);
        }
         set("armor_prop/armor", 1);
         set("armor_prop/int", 2);
        setup();
}

