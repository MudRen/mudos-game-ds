#include <ansi.h>
#include <armor.h>
inherit PANTS;
void create()
{
        set_name(WHT"籐承膝"NOR ,({ "kneel pants","pants" }) );
        set("long",
"一條籐蔓所捲成的短褲,只到膝蓋,據說是蚩尤東征時期所自製的。\n"
);
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/str", 1); 
        set("armor_prop/int",2);        
setup();
}


