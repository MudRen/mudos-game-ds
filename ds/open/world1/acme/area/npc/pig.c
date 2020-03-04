#include <ansi.h>
inherit NPC;
void create()
{
        set_name("野豬",({ "pig" }) );
        set("race", "野獸");
        set("age",6);
        set("long", "牠是生活在深山的野豬，看來相當的強壯，還長了長長的獠牙。\n"
);
        set("level",14);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "野豬用他的獠牙往地上掘了幾下，不知在找啥什麼。\n", }) );
        setup();
}
