#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
	set_name(HIY"黃金護手"NOR, ({ "gold gloves" , "gloves"}) );
        set("long",@LONG
這是由黃金蜈蚣的賤肢所造成的護手。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "雙");
                set("value",2500);
		set("no_sell", 1);
        }
        setup();
}

