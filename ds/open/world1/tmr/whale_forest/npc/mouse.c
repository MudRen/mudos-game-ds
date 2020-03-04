// horse.c

#include <npc.h>

void create()
{
        set_name("山鼠", ({ "wild mouse","mouse" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set_stat_maximum("gin", 30);
        advance_stat("hp",20);
        set("age", 1);
        set("long", "一隻野生的山鼠，正潛伏在草叢裡，張著雙眼望著你\n");
        setup();
}

