#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(HIB "魔星磐龍帶" NOR,({ "devil-waist","waist" }) );
        set("long",
"這是一條龍形的腰帶，有一股神秘的氣息。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "條" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", -1);
        set("armor_prop/int", 2);
        set("armor_prop/str", -1);
        }
        setup();
}
