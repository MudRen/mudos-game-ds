#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIB"���Ѿu"NOR,({ "chaos cloak","cloak" }) );
        set("long","�Ѥ��]������w�ƦӦ����ܭ��C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",4000);
                set("armor_prop/armor", 20);
        }
        setup();
}


