#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"絕世"HIW"好"HIC"劍"NOR, ({ "best sword","sword"} ) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
        set("material","diamond");
                set("long", "這是一把舉世無雙的劍。\n");
                set("value", 1000);
}
    set("weapon_prop/bar",11);
        init_sword(100);
        setup();
}

