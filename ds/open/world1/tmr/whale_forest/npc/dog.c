// dog.c

#include <npc.h>

void create()
{
        set_name("����", ({ "dog" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set_stat_maximum("gin", 20);
        advance_stat("hp",50);
        set_stat_notify("hp", 20);
        set("age", 6);
        set("long", "�@��ż�����������A���|�B��F��Y�C\n");
        setup();
}


