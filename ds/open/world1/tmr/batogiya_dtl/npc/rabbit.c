// rabbit.c

#include <npc.h>

void create()
{
    set_name("野兔", ({ "wild rabbit","rabbit" }) );
    set_race("beast");
    set("long", "一條兩眼靈動有神的野兔，正在草地裡蹦蹦跳跳地玩耍。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("cps", 2);

    set("age", 1);

    setup();

}
