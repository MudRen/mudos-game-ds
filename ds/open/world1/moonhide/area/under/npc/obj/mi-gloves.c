#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIR"祕 "HIG"星掌"NOR,({ "mi gloves","gloves" }) );
        set("long","一對神祕的手套。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 8);
        }
        setup();
}

