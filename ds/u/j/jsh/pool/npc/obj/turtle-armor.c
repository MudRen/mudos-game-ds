#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(CYN"玄"HIW"之"CYN"武"HIW"甲"NOR,({ "shang-woo armor","armor" }) );
        set("long","由玄武神龜之殼所成的盔甲，十分笨重，但防禦力十足。\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "件" );
                set("value",6000+random(1030));
                set("armor_prop/armor", 42);
        }
        setup();
}


