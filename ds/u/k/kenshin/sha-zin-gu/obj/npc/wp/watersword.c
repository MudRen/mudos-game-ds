#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"水舞劍"NOR, ({ "water-dance sword", "sword" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的劍，此劍鋒利無比，但是勁道不足，所以只適合初學劍士專用。\n");
                set("value", 1700);
                set("material", "steel");
}
        init_sword(30);
        set("weapon_prop/tec", 1);
                setup();
}

