#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(HIB"渾天褲"NOR,({ "chaos pants","pants" }) );
        set("long","由天魔的角質硬化而成的褲子。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",4000);
        }  
        set("armor_prop/str",1); 
        set("armor_prop/armor", 9);  
        setup();
}

