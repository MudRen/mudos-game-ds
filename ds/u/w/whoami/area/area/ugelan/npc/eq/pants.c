#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name("�֥��u��"NOR, ({ "short pants","pants" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���L���u�ǡE\n");
                set("unit", "��");
                set("value",100);
                set("material", "fur");
                set("armor_prop/armor", 5);
        }
       setup();
}
