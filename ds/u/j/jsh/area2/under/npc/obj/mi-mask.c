#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIR"�� "HIG"�@��"NOR,({ "mi mask","mask" }) );
        set("long","�@�󯫯�������C\n");
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

