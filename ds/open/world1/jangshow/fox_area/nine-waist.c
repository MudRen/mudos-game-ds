#include <armor.h>
#include <ansi.h>
inherit WAIST;
 
void create()
{
        set_name(HIW"�E���ȧ�"NOR,({ "nine-fox waist","waist" }) );
        set("long",HIW"�E�����������ڡA�i�H�����@��A���y�a�A��Ωʬ۷��C\n"NOR);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "��" );
        set("value",10000); 
        }     
        set("armor_prop/armor", 5);  
        set("armor_prop/str",2);
        set("armor_prop/int",2);
        set("armor_prop/bar",-1);
        setup();
}
