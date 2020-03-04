#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老虎", ({ "tiger" }) );
        set("race", "野獸");
        set("age", 25);
        set("long", "一隻威風凜凜的老虎，看來似乎正瞪著你。\n"
);
        set("level",20);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "老虎低聲的吼著。\n",
        }));
        setup();
}
