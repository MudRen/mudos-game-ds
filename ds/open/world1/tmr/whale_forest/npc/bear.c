// bear.c

#include <npc.h>

void create()
{
        set_name("小黑熊", ({ "small bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 5);
          set_attr("cps", 5);
        set("long", "一隻野生的小黑熊，正用爪子抓著樹幹，似乎在磨指甲似。\n");
        setup();
	set_stat_maximum("hp",200);
}


