#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"修羅神鞋〥"NOR, ({ "shu lo boots","boots" }) );
        set_weight(2800);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","四大塔王之一的燕非彥使用的防具。\n");
                set("unit", "雙");
        set("value",4900);
                set("material","cold");
                 set("armor_prop/con",1);
                 set("armor_prop/armor", 15);
        }
        setup();
}

