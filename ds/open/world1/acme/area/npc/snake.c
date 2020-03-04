#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小蛇", ({ "small snake","snake" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "牠是一隻不到半尺的黑色小蛇，應該是不俱毒性。\n");
        set_temp("apply/hit",-20);
        set_temp("apply/dodge",-10);
        set("level",1);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        setup();
}
