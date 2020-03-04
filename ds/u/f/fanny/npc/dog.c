#include <ansi.h>
inherit NPC;
void create()
{
        set_name("野狗", ({ "dog" }) );
        set("race", "野獸");
        set("age", 5);
        set("long", "牠是一隻全身髒兮兮的野狗。\n"
);
        set("level",2);
        set("dex",-1);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
          (: random_move :),
                "野狗對著你吠叫了幾聲。\n",
        }));
        setup();
}

