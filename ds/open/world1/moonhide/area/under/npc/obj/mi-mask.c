#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIR"祕 "HIG"護面"NOR,({ "mi mask","mask" }) );
        set("long","一件神祕的面具。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 5);
        }
        setup();
}

