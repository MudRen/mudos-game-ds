#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"火龍皮靴"NOR ,({ "fire boots" , "boots"  }) );
        set("long","這是一雙深紅色泛著火光的皮靴。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(100);
        set("material", "boots");
        set("unit", "雙" );
        set("value",50);
        set("armor_prop/armor", 80);
        set("armor_prop/dodge", 80);
        }
        setup();
}
