#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(HIR"祕 "HIG"鑫褲"NOR,({ "mi pants","pants" }) );
        set("long","一件神祕的毛褲。\n");
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

