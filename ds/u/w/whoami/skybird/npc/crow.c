#include <ansi.h>
inherit NPC;
void create()
{
        set_name("烏鴉",({ "crow" }) );
         set("level",10);
        set("race", "野獸");
        set("age", 3);
        set("long", "一隻攻擊性頗強的小動物。\n");
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾羽", "羽翼" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
}