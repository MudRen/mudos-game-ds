#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("鐵護胸",({"iron chest protector","protector"}) );
	set("long",@LONG
這是一件用鐵片接合而成的護胸。
LONG
);
	set_weight(8850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件");
        }
        set("armor_prop/armor",16);
        setup();
        set("value",2330);
        set("volume", 8);
}

int query_autoload() { return 1; }
