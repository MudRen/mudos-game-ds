#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIW"白銀長護手"NOR ,({ "silver gloves","gloves" }) );
        set("long","一雙純銀色略帶殺氣的鋼護手\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "steel");
        set("unit", "雙" );
        set("value",50);
        set("armor_prop/armor", 50);
        }
        setup();
}
