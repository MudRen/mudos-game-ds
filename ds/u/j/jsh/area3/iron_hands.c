#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(WHT"鐵護腕"NOR,({ "iron hands","hands" }) );
        set("long","這是一件完全用鐵造成的護腕[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",300);
                set("armor_prop/shield", 5); 
                set("armor_prop/armor", 20);
               
        }
        setup();
}

