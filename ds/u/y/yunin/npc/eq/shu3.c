#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(HIR"修羅綁腿〥"NOR ,({ "shut lo leggings","leggings" }) );
        set("long","四大塔王之一的燕非彥使用的防具。\n");
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("material", "cold");
        set("volume",3);
        set("unit", "雙");
        set("value",3900);
        }
        set("armor_prop/armor",3);
        set("armor_prop/con",1);
        setup();
}


