#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIR"�� "HIG"�Z�T"NOR,({ "mi hands","hands" }) );
        set("long","�@�ﯫ�����@�áC\n");
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

