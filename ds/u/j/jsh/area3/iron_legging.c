#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(WHT"�K�@��"NOR,({ "iron leggings","leggings" }) );
        set("long","�o�O�@�󧹥����K���y���@��[0;1;36m�[1mA[0m���m�O���t[0;1;36m�[1mC[0m\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",500);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge",-5);
        }
        setup();
}

