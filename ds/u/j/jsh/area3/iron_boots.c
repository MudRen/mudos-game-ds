#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(WHT"鐵步足"NOR,({ "iron boots","boots" }) );
        set("long","這是一件完全用鐵造成的鞋子[0;1;36m�[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",600);
                set("armor_prop/armor", 5); 
               set("armor_prop/dodge", -3);
                
        }
        setup();
}

