#include <npc.h>

void create()
{
        set_name("兇暴灰熊", ({ "crazy bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 5);
        set("long", "一隻兩眼發紅的灰熊，好像要把你吃了下去一樣。\n");
        setup();
        set_level(5);
        set_stat_maximum("hp",450);
        carry_object(__DIR__"obj/bear-paw");
}

