#include <armor.h>
inherit HANDS;

void create()
{
        set_name("Arai手套",({"arai gloves","gloves"}));
        set("long",@LONG
這是一雙日本進口的Arai賽用手套。
LONG);
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");
                set("material", "skin");
                set("limit_level",30);
        }
        set("armor_prop/armor",6);
        setup();
        set("value",4000);
        set("volume", 2);
}
int query_autoload() { return 1; }
