// dog.c

#include <npc.h>

void create()
{
        set_name("野狗", ({ "dog" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set_stat_maximum("gin", 20);
        advance_stat("hp",50);
        set_stat_notify("hp", 20);
        set("age", 6);
        set("long", "一條髒兮兮的野狗，正四處找東西吃。\n");
        setup();
}


