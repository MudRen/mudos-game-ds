#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("連衣裙",({"dress"}) );
	set("long",@LONG
這是一件常見的連身長裙。
LONG);
	set_weight(970);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("female_only",1);
        set("armor_prop/armor",5);
        setup();
        set("value",700);
        set("volume", 4);
}
int query_autoload() { return 1; }
