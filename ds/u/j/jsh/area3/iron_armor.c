#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(WHT"鐵胄甲"NOR,({ "iron armor","armor" }) );
        set("long","這是一件完全用鐵打造的胄甲[0;1;36m�[1mA[0m防禦力不差[0;1;36m�[1mC[0m\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",1500);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge",-10);
        }
        setup();
}

