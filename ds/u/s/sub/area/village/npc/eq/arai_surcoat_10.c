#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name("Arai護肩",({"arai shoulder cap","shoulder","cap"}) );
        set("long",@LONG
這是一副日本進口的Arai護肩。
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "副");
                set("limit_level",30);
        }
        set("value",2200);
        set("armor_prop/armor",10);
        setup();
        set("volume", 4);
}
int query_autoload() { return 1; }
