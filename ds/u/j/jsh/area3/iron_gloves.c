#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(WHT"�K����M"NOR,({ "iron gloves","gloves" }) );
        set("long","�o�O�@�󧹥����K���s������M[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",300);
                set("armor_prop/shield", -2); 
                set("armor_prop/armor", 12);
               
        }
        setup();
}

