#include <npc.h>

void create()
{
    set_name("�j�D", ({ "big snake", "snake" }) );
    set_race("beast");
    set("long", "�@���g�Ŧ⪺�j�D�A���Y�@�R�@�Y���C\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("cor", 7);

    set("age", 1);

    setup();

        advance_stat("gin",50);
        advance_stat("hp",100);
    set_level(5);
    if( random(100) > 85 ) carry_object(__DIR__"obj/gall");
}
