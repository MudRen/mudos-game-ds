#include <ansi.h>
inherit NPC;
void create()
{
        set_name("母老虎", ({ "tigress" }) );
        set("race", "野獸");
        set("age", 23);
        set("long", "一隻兇巴巴的母老虎，看來似乎正瞪著你。\n"
);
        set("level",20);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "母老虎像隻小貓一樣靠在老虎身上。\n",
        }));
        setup();
}
