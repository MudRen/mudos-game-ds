#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("布鞋" ,({ "boots" }) );
        set("long","這是一雙普通的布鞋。\n");
set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "boots");
        set("unit", "雙" );
        set("value",50);
	set("volume",2);
        }
        set("armor_prop/armor", 1);
        setup();
}

