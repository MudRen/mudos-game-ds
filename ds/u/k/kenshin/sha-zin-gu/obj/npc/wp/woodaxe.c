#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(YEL"巨木斧"NOR, ({ "wood axe", "axe" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的斧，此斧面鋒利，但是勁道不足，所以只適合初習斧的人專用。\n");
                set("value", 2000);
                set("material", "steel");
}
        init_axe(32);
        set("weapon_prop/wit", 1);
                setup();
}

