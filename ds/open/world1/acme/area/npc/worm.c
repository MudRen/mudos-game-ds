#include <ansi.h>
inherit NPC;
void create()
{
        set_name("沙蟲", ({ "worm" }) );
        set("race", "野獸");
        set("age", 5);
        set("long", 
            "牠是一隻很大的蟲，約有手掌般大，只見牠把沙吞了進去\n"
            "，又吐了出來，不知在做啥。\n",
            );
        set("level",2);
        set("dex",-1);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite"}) );
        setup();
}

