
#include <npc.h>

void create()
{
        set_name("松鼠", ({ "squirrel" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set("age", 5);
        set_attr("cps", 1);
        set_attr("str", 2);
        set_attr("con", 2);
        set("long", "一隻靈巧的小松鼠，正在樹枝間穿來穿去。\n");
        setup();
        set_stat_maximum("hp",50);
}

