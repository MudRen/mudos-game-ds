#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIR"焰火刀"NOR, ({ "fire blade", "blade" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的刀，此刀炳鋒利，但是勁道不足，所以只適合初習刀的人專用。\n");
                set("value", 2000);
                set("material", "steel");
}
        init_blade(30);
        set("weapon_prop/sou", 1);
                setup();
}

