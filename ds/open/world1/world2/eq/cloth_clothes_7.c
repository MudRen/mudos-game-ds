#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("運動服",({"short clothes","clothes"}) );
	set("long",@LONG
這是一件藍白相間的運動服，十分有彈性。
LONG);
	set_weight(1370);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",7);
        setup();
        set("value",910);
        set("volume", 4);
}
int query_autoload() { return 1; }
