// horse.c

#include <npc.h>

void create()
{
        set_name("�s��", ({ "wild mouse","mouse" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set_stat_maximum("gin", 30);
        advance_stat("hp",20);
        set("age", 1);
        set("long", "�@�����ͪ��s���A�����b���O�̡A�i��������ۧA\n");
        setup();
}

