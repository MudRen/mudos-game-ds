#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"萬年龍"NOR, ({ "thousand year dragon","dragon","year" }));
        set("long","幼龍之中資歷較深，但依然不具任何殺傷力。\n");

        set("race","野獸");
        set("level", 3);
        set("age", 1000);

        set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

