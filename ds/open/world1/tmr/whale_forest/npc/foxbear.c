// fox bear.c

#include <npc.h>

void create()
{
        set_name("�p����", ({ "small fox bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw" }) );
        set("age", 5);
        set("long", "�@�����ͪ��p�����A�@�����«G�R����������ۧA�C\n");
        setup();
        set_stat_maximum("hp",200);
        set_stat_maximum("gin",200);
           do_heal();
}


