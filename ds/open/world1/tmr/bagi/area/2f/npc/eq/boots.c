#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"左極馬靴"NOR,({ "joh ji boots","boots" }) );
        set("long","這是一件官兵所穿著的馬靴，是由動物的皮所編織而成，很耐穿。\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",2);
        set("material","skin");
        set("unit", "件" );
        set("value",1250);
                set("armor_prop/armor", 7);
                set("armor_prop/shield",3);
        }
        setup();
}

