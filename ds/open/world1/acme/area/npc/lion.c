#include <ansi.h>
inherit NPC;
void create()
{
        set_name("獅子",({ "lion" }) );
        set("level",16);
        set("race", "野獸");
        set("age", 6);
        set("long","牠是一隻正在吃著花鹿屍體的獅子。\n");
        set("attitude", "aggressive");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
