// rabbit.c

#include <npc.h>

void create()
{
        set_name("野兔", ({ "wild rabbit","rabbit" }) );
        set_race("beast");
        set_stat_maximum("gin", 30);
        set("verbs", ({ "bite", "crash"}) );
        advance_stat("hp",50);
        set("age", 1);
          set_attr("cps", 2);
        set("long", "一條兩眼靈動有神的野兔，正在草地裡蹦蹦跳跳地玩耍。\n");
        setup();
}


