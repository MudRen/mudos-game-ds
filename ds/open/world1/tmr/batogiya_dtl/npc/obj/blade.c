#include <weapon.h>

inherit F_BLADE;

void create()
{
    set_name("哈粒剝落刀", ({ "ha lipoluo blade", "blade" }) );
    set_weight(2000);
    setup_blade(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"blade"}));
        set("unit", "把");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "一把哈哈村特製的短刀，上頭還刻畫著一個笑臉，十分有趣。\n");
    }
    setup();
}
