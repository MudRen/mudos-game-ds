#include <ansi.h> 
#include <armor.h>
inherit PANTS;

void create() 
{
        set_name(HIR"紅毛褲"NOR,({ "red pants","red","pants" }) );
        set("long","一件紅色的絨毛褲。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","leather");
                set("unit", "件" );
       set("value",2000);
set("armor_prop/armor", 10); 
set("armor_prop/dodge", 4);
                
        }
        setup();
}

