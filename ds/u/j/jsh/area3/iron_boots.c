#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(WHT"�K�B��"NOR,({ "iron boots","boots" }) );
        set("long","�o�O�@�󧹥����K�y�����c�l[0;1;36m�[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",600);
                set("armor_prop/armor", 5); 
               set("armor_prop/dodge", -3);
                
        }
        setup();
}

