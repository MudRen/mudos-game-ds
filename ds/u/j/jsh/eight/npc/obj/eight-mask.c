#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIC"�äѭ���"NOR,({ "turn-sky mask","mask" }) );
        set("long","�K�j�{�̪��äѭ{�A�Ҹ˪�����C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",3000);
                set("armor_prop/armor", 5);
        }
        setup();
}

