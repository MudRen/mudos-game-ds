#include <ansi.h>
inherit NPC;
void create()
{
       set_name("食骨巨蟲",({"eat bone bug","bug"}));
        set("level",12);
        set("race", "野獸");
        set("age", 300);
        set("long", "這是非常大的蟲，牠最喜歡吃骨頭。\n");
        set("limbs", ({ "頭部", "身體", "尾部"}) );
        set("verbs", ({ "bite"}) );
        setup();
}
