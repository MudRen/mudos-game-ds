#include <armor.h>
#include <ansi.h> 
inherit WAIST;
void create()
{
        set_name(HIR"���b�a"NOR,({ "blood-snake waist","waist" }) );
        set("long","��몺���q���n�A���G�S������\\�ΡC\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
        set("unit", "��" );
        set("value",2000);
        set("armor_prop/armor", 8); 
        }
        setup(); 
}

