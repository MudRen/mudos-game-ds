#include <armor.h>
#include <ansi.h>
inherit ARMOR; 

void create()
{
        set_name(RED"天魔鎧甲"NOR,({ "evil armor","armor" }) );
        set("long","天魔身上所穿的盔甲，防禦力自然不在話下。\n");
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",5);
         set("material","golden");
         set("unit", "件" );
         set("value",30000);
               
   }  
        set("armor_prop/armor", 40);
        set("armor_prop/parry", 5);
        set("armor_prop/dodge", -10);
        //以上經alickyuen重寫及改動
        setup();
}
