#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("Ｃ級強化鐵甲",({"c-iron armor","armor"}) );
	set("long",@LONG
這是一件由純鐵打造而成的厚重護甲，並經過Ｃ級強化認證。
LONG
);
	set_weight(13050);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件");
        }
        set("armor_prop/armor",23);
        setup();
        set("value",4680);
        set("volume", 10);
}

//int query_autoload() { return 1; }
