#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(WHT"鐵面具"NOR,({ "iron mask","mask" }) );
        set("long","這是一件完全用鐵打造的面具[0;1;36m�[1mA[0m防禦力不差[0;1;36m�[1mC[0m\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",300);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge",-2);
        }
        setup();
}

