#include <weapon.h>
#include <ansi.h>

inherit FIST;

void create()
{
        set_name(HIG"土絕爪"NOR, ({ "to claw", "claw" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的爪，此爪鋒利，但是勁道不足，所以只適合初習爪的人專用。\n");
                set("value", 2500);
                set("material", "steel");
}
        init_fist(31);
        set("weapon_prop/wit", 1);
                setup();
}


