#include <ansi.h>
inherit NPC;
void create()
{
set_name("蟬",({"cicada"}));
        set("level",25);
        set("race", "野獸");
        set("age", 4);
        set("long", "這是一隻嘰嘰叫的蟬。\n");
        set("limbs", ({ "頭部", "身體", "翅膀" }) );
        set("verbs", ({ "bite", "crash" }) );
        setup();
}
