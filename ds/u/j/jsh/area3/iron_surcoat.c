#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(WHT"鐵絲披風"NOR,({ "iron surcoat","surcoat" }) );
        set("long","這是一件完全用鐵絲編成的披風[0;1;36m�[1mA[0m外型醜陋[0;1;36m�[1mA[0m但防禦力高[0;1;36m�[1mC[0m\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",800);
                set("armor_prop/armor", 10);
                
        }
        setup();
}

