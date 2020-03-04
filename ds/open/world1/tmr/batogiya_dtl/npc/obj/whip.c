#include <weapon.h>

inherit F_WHIP;

void create()
{
    set_name("哈粒剝落鞭", ({ "ha lipoluo whip", "whip" }) );
    set_weight(2000);
    setup_whip(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"whip"}));
        set("unit", "把");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "一把哈哈村特製的短鞭，上頭還刻畫著一個笑臉，十分有趣。\n");
    }
    setup();
}
