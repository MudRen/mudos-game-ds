#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("Arai龜殼",({"arai armor","armor"}) );
        set("long",@LONG
這是一件日本進口的Arai龜殼，它可以保護使用者的脊椎不受到外力
的傷害，以確保安全。
LONG
);
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "件");
                set("limit_level",30);
        }
        set("armor_prop/armor",25);
        setup();
        set("value",24500);
        set("volume", 30);
}
int query_autoload() { return 1; }
