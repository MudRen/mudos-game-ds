#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(CYN"流雲護手"NOR ,({ "gloves" }) );
        set("long","一雙深藍色的護手\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "steel");
        set("unit", "雙" );
        set("value",50);
        set("armor_prop/armor", 1000);
        }
        setup();
}
