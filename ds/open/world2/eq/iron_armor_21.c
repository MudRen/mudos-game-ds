#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("鐵護甲",({"iron armor","armor"}) );
	set("long",@LONG
這是一件由純鐵打造而成的厚重護甲。
LONG
);
	set_weight(12250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件");
        }
        set("armor_prop/armor",21);
        setup();
        set("value",3880);
        set("volume", 10);
}

int query_autoload() { return 1; }
