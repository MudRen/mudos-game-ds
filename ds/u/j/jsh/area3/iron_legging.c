#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(WHT"鐵護膝"NOR,({ "iron leggings","leggings" }) );
        set("long","這是一件完全用鐵打造的護膝[0;1;36m�[1mA[0m防禦力不差[0;1;36m�[1mC[0m\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",500);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge",-5);
        }
        setup();
}

