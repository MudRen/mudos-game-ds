#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIR"祕 "HIG"浮風"NOR,({ "mi cloak","cloak" }) );
        set("long","一匹神祕的披風。\n");
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

