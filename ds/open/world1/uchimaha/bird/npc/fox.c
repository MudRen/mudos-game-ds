#include <ansi.h>
inherit NPC;
void create()
{
       set_name("狐狸",({"fox"}));
        set("level",10);
        set("race", "野獸");
        set("age", 14);
        set("long", "這是一隻狐狸。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
