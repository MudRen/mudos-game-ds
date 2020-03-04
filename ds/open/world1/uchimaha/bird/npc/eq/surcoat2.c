#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("羽毛披風", ({ "bird surcoat", "surcoat" }) );
        set("long",
                "這是一件用羽毛製成的披風, 雖然非常輕薄, 但是防禦力也不壞。\n");
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  7);
                set("limit_dex",10);
                set("armor_prop/dex", 1);
                set("material", "silk");
        }
        setup();
}


