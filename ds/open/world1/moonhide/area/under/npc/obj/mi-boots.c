#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"祕 "HIG"步足"NOR,({ "mi boots","boots" }) );
        set("long","一雙神祕的鞋子。\n");
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

