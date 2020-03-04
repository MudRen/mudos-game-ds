#include <npc.h>

void create()
{
    set_name("野豬", ({ "wild boar", "boar" }) );
    set_race("beast");
    set("long", "一隻身體相當肥大的野豬，正在用嘴在地上挖來挖去。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("con", 2);

    set("age", 1);

    setup();

        advance_stat("gin", 30);
        advance_stat("hp", 50);
    set_level(2);
}
