#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(WHT"�K�H��"NOR,({ "iron armor","armor" }) );
        set("long","�o�O�@�󧹥����K���y���H��[0;1;36m�[1mA[0m���m�O���t[0;1;36m�[1mC[0m\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",1500);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge",-10);
        }
        setup();
}

