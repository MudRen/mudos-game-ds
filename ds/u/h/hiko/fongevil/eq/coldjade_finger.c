#include <armor.h>
inherit FINGER;
void create()
{
        set_name("寒玉戒" ,({ "cold-jade finger","finger" }) );
        set("long","這是一只用寒玉的所製的戒，是用來陪葬的飾品。\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","只");
                set("material", "jade");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/dex",2);
        set("value",3000);
        set("limit_lv",10);
        setup();
}


