#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(WHT"�K�@��"NOR,({ "iron hands","hands" }) );
        set("long","�o�O�@�󧹥����K�y�����@��[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",300);
                set("armor_prop/shield", 5); 
                set("armor_prop/armor", 20);
               
        }
        setup();
}

