#include <npc.h>

void create()
{
          set_name("野狼", ({"wild wolf","wolf" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw" }) );
        set("age", 5);
        set("long", "一隻兇狠的野狼，正繞著地上的一沱血跡打轉。\n");
        setup();
        set_level(5); 
}

