#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"������M"NOR,({ "red finger","finger" }) );
        set("long","�@�u�������񪺫��M[0;1;36m�[1mA[0m�n�����_�S����O[0;1;36m�[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10); 
                set("armor_prop/str",1);        }
        setup();
}

