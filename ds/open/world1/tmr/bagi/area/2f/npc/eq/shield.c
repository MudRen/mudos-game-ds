#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(HIY"左極之盾"NOR,({ "joh ji shield","shield" }) );
        set("long","這是一件官兵所使用的盾牌，盾牌外觀刻著一頭猛虎，十分好看。\n");
        set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
                set("unit", "件" );
                set("value",1000);
                set("armor_prop/armor", 8);
                set("armor_prop/shield",2);
        }
        setup();
}

