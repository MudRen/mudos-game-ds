#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("羽毛護腕", ({ "feather wrists", "wrists" }) );
        set("long",
                "這是一件用羽毛製成的護腕, 雖然非常輕薄, 但是防禦力也不壞。\n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙" );
                set("value",200);
                set("armor_prop/armor",  4);
                set("limit_dex",10);
                set("armor_prop/dex", 1);
                set("material", "silk");
        }
        setup();
}


