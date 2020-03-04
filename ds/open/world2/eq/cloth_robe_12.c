#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("白色長袍",({"white cloth robe","robe","white robe"}) );
	set("long",@LONG
這是一件白色的長袍，長袍上散發著一股淡淡的檀香味。
LONG
);
	set_weight(3250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",12);
        set("armor_prop/shield",6);
        set("armor_prop/int",1);
        setup();
        set("value",1160);
        set("volume", 6);
}

int query_autoload() { return 1; }
