#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR"祕 "HIG"反盅"NOR,({ "mi helmet","helmet" }) );
        set("long","一頂神祕的頭盔。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 12);
        }
        setup();
}

