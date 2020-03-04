#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIB "魔星鬼面" NOR,({ "devil-mask","mask" }) );
        set("long",
"這是一副形如夜叉的面具，形狀十分恐怖，手工非常精細。\n"
);
        set_weight(1900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "副" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", -2);
        set("armor_prop/int", -2);
        set("armor_prop/str", 3);
        }
        setup();
}
