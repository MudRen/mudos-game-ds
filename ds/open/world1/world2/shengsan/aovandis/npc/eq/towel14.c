#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("浴巾",({"bath towel","towel"}) );
	set("long",@LONG
這是一件藍色的大浴巾。
LONG
);
	set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("auto_set",2);
        setup();
}

// int query_autoload() { return 1; }
