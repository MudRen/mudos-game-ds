#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"祕 "HIG"指套"NOR,({ "mi finger","finger" }) );
        set("long","一只神祕的指套。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 4);
        }
        setup();
}

