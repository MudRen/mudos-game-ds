#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"飛天龍"NOR, ({ "fly dragon","fly","dragon" }));
        set("long","龍王身邊的護衛，具有一定的殺傷力。\n");

        set("race","野獸");
        set("level", 13);
        set("age", 533);

        set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

