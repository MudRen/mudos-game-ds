#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"祕 "HIG"胄甲"NOR,({ "mi armor","armor" }) );
        set("long","一件神祕的冑甲。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",3000);
                set("armor_prop/armor", 30);
                set("armor_prop/parry", 6);
        }
        setup();
}

