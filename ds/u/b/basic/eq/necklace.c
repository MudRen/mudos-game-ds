#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIM"���嫬"HIW"����"NOR, ({"basic necklace","necklace","basic"
}) );
        set("long", "Basic�eching���ͤ�§���C\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  100);
        set("material","gold");
                set("value", 10000);
        }
        setup();
}
