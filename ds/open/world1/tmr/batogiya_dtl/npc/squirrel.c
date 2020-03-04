#include <npc.h>

void create()
{
    set_name("松鼠", ({ "squirrel" }) );
    set_race("beast");
    set("long", "一隻動作迅速的小松鼠，不時的左右張望。\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("dex", 2);

    set("age", 1);

    setup();

}
