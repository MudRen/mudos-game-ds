#include <armor.h>
inherit PANTS;

void create()
{
        set_name("Arai皮褲",({ "arai pants","pants" }) );
        set("long",@LONG
這是一件日本進口的Arai皮褲。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "件");
                set("limit_level",30);
        }
        set("armor_prop/armor",17);
        setup();
        set("value",9000);
        set("volume",4);
}
int query_autoload() { return 1; }
