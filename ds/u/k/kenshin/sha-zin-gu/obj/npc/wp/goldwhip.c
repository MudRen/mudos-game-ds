#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIY"金眩鞭"NOR, ({ "gold whip", "whip" }));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "暇日谷王師傅所打造的鞭，此鞭鋒利無比，但是勁道不足，所以只適合初習鞭的人專用。\n");
                set("value", 2000);
                set("material", "steel");
}
        init_whip(32);
        set("weapon_prop/sou", 1);
                setup();
}

