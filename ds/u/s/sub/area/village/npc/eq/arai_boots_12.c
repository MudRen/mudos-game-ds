#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("Arai賽車靴",({"arai boots","boots"}) );
        set("long",@LONG
這一雙日本原裝進口的Arai賽車靴，相當的厚重。
LONG
);
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "雙");
                set("limit_level",30);
        }
        set("value",3450);
        set("armor_prop/armor",12);
        setup();
        set("volume", 4);
}
int query_autoload() { return 1; }
