#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(HIB "魔星護腕" NOR,({ "devil-wrisit","wrisit" }) );
        set("long",
"這是一個好用的護腕，是風靡一時的好裝備。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "個" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", -1);
        set("armor_prop/int", -3);
        set("armor_prop/con", 1);
        }
        setup();
}

