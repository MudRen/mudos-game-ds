#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(WHT"鐵戒指"NOR,({ "iron ring","ring" }) );
        set("long","這是一件完全用鐵打造的戒指[0;1;36m�[1mA[0m造型美觀[0;1;36m�[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",100);
                set("armor_prop/armor", 3);
                set("armor_prop/shield",3);
        }
        setup();
}

