#include <ansi.h>
inherit NPC;
void create()
{
       set_name("大狐狸",({"big fox", "fox"}));
        set("level",20);
        set("race", "野獸");
        set("age", 16);
        set("long", "這是一隻體型跟你差不多大的巨大狐狸。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
