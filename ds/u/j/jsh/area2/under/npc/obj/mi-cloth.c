#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIR"�� "HIG"�P�m"NOR,({ "mi cloth","cloth" }) );
        set("long","�@�󯫯����W��C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",3000);
                set("armor_prop/armor", 10);
        }
        setup();
}

