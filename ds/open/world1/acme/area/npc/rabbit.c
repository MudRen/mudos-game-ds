#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "小白兔" NOR ,({ "rabbit" }) );
        set("level",1);
        set("race", "野獸");
        set("age", 1);
        set("long", "牠是一隻可愛的小白兔。\n");
set_temp("apply/hit",-10);
set_temp("apply/dodge",-10);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        setup();
}
