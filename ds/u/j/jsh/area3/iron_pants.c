#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(WHT"鐵絲褲"NOR,({ "iron pants","pants" }) );
        set("long","這是一件完全用鐵絲編成的褲子，非常輕巧[0;1;36m�[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",600);
                set("armor_prop/armor", 2); 
               set("armor_prop/dodge", 3);
                
        }
        setup();
}

