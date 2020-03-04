#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("道鞋", ({ "taoist sandal", "sandal" }) );
        set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "一雙道士常穿的鞋子, 輕巧方便。\n");
                set("unit", "雙");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dex",1);
                set("value", 1200);
        }
        setup();
}