#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("木鞋" ,({ "wood boots","boots" }) );
        set("long","這是一雙純手工，並由木頭製成的鞋子，看起來相當耐穿。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "boots");
        set("unit", "雙" );
        set("value",120);
        }
set("armor_prop/armor", 2);
        setup();
}
