#include <ansi.h>
inherit NPC;
void create()
{
       set_name("飛鼠",({"sciurine"}));
        set("level",15);
        set("race", "野獸");
        set("age", 2);
        set("dex",-2);
        set("long", "牠是一隻生長在林間的飛鼠。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}


