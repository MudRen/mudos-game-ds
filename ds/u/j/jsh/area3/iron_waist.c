#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(WHT"�K�y�P"NOR,({ "iron waist","waist" }) );
        set("long","�o�O�@�󧹥����K�y�����y���K�P�A���m�O��[0;1;36m�[1mC[0m\n");
        set_weight(700);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",700);
                set("armor_prop/armor", 7); 
                               
        }
        setup();
}

