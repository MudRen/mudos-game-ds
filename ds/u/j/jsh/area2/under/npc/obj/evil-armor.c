#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"天魔鎧甲"NOR,({ "evil armor","armor" }) );
        set("long","天魔身上所穿的盔甲，防禦力自然不在話下。\n");
        set_weight(15000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",20000);
                set("armor_prop/armor", 46);
                set("armor_prop/parry", 10); 
                set("armor_prop/dodge",-10);   
 
    }
        setup();
}

