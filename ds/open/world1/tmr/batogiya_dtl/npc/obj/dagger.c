#include <weapon.h>

inherit F_DAGGER;

void create()
{
    set_name("哈粒剝落匕", ({ "ha lipoluo dagger", "dagger" }) );
    set_weight(2000);
    setup_dagger(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"dagger"}));
        set("unit", "把");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "一把哈哈村特製的短匕，上頭還刻畫著一個笑臉，十分有趣。\n");
    }
    setup();
}
