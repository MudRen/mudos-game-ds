#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(WHT"�K�޵P"NOR,({ "iron shield","shield" }) );
        set("long","�o�O�@�󧹥����K���y���޵P[0;1;36m�[1mA[0m���m�O��[0;1;36m�[1mC[0m\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10);
        }
        setup();
}

