#include <ansi.h>
inherit NPC;
void create()
{
        set_name("野猴",({ "monkey" }) );
        set("race", "野獸");
        set("age",6);
        set("long", "牠是生活在深山的野猴，看來相當的可愛。\n");
        set("level",20);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "野猴在樹上盪來盪去，看起來十分快樂。\n", }) );
        setup();
}


