#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("神武護腕" ,({ "god wrists","wrists" }) );
        set("long","這是一個神武教門徒專用的基本防具。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "linen");
        set("unit", "個" );
        set("value",300);
        }
         set("armor_prop/armor", 1);
         set("armor_prop/shield", 1);
         set("armor_prop/int", 1);
        setup();
}
