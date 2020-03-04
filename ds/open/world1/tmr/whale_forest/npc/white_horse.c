// horse.c

#include <npc.h>

void create()
{
        set_name("野白馬", ({ "wild horse","horse" }) );
        set_race("beast");
        set("verbs", ({ "bite", "crash" }) );
        set_stat_maximum("gin", 40);
        advance_stat("hp",50);
          set_attr("cps",1);
        set("age", 3);
        set("long", "一隻野生的白馬，正低著頭吃著草，不時地抬起頭望望你\n");
        setup();
}

