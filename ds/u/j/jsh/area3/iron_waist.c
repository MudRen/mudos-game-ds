#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(WHT"鐵腰牌"NOR,({ "iron waist","waist" }) );
        set("long","這是一件完全用鐵造成的腰間鐵牌，防禦力高[0;1;36m�[1mC[0m\n");
        set_weight(700);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",700);
                set("armor_prop/armor", 7); 
                               
        }
        setup();
}

