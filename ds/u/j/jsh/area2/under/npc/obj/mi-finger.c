#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"�� "HIG"���M"NOR,({ "mi finger","finger" }) );
        set("long","�@�u���������M�C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",3000);
                set("armor_prop/armor", 4);
        }
        setup();
}

