#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("昊戠長靴" ,({ "hao chi boots","boots" }) );
        set("long","這是一雙官兵常穿黑色長靴。\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "雙" );
		set("value",500);
        }
         set("armor_prop/armor", 3);
         set("armor_prop/dodge", 2);
        setup();
}
