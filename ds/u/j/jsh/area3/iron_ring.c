#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(WHT"�K�٫�"NOR,({ "iron ring","ring" }) );
        set("long","�o�O�@�󧹥����K���y���٫�[0;1;36m�[1mA[0m�y�����[[0;1;36m�[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",100);
                set("armor_prop/armor", 3);
                set("armor_prop/shield",3);
        }
        setup();
}

