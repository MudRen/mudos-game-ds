#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(WHT"�K����"NOR,({ "iron neck","neck" }) );
        set("long","�o�O�@�󧹥����K���y���޵P[0;1;36m�[1mA[0m���m�O��[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",200);
                set("armor_prop/armor", 5);
                
        }
        setup();
}

