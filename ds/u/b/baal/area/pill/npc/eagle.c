#include <ansi.h>
inherit NPC;
void create()
{
        set_name("獵鷹",({ "eagle" }) );
         set("level",12);
        set("race", "野獸");
        set("age", 3);
        set("long", "牠是一隻在高山上才見得到的鷹。\n");
        set("limbs", ({ "頭部", "翅膀", "前爪", "後爪", "尾羽", }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

