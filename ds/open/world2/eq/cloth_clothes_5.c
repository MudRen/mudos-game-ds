#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("白襯衫",({"white shirts","shirts"}) );
	set("long",@LONG
這是一件白色的襯衫，通常用在較正式的場合。
LONG);
	set_weight(770);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",455);
        set("volume", 4);
}
int query_autoload() { return 1; }
