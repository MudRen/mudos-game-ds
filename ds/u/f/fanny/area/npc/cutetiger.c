#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小老虎", ({ "small tiger","tiger" }));
        set("race", "野獸");
        set("age", 5);
        set("long", "一隻很可愛的小老虎，正和牠的兄弟們玩得不亦樂乎。\n"
);
        set("level",10);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "小老虎偷偷的捏了老虎一下。\n",
        }));
        setup();
}
