#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(CYN"�y�����u"NOR ,({  "boots"  }) );
        
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(100);
        set("material", "boots");
        set("unit", "��" );
        set("value",50);
        set("armor_prop/armor", 1000);
        set("armor_prop/dodge", 1000);
        }
        setup();
}
