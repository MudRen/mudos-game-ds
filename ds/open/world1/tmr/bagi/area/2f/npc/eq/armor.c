
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"左極胄甲"NOR,({ "joh ji armor","armor" }) );
        set("long","這是一件官兵所穿著的戰甲，十分耐穿。\n");
        set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
        set("unit", "件" );
        set("value",4500);
        set("armor_prop/armor", 22);
        set("armor_prop/shield",10);
        }
        setup();
}

