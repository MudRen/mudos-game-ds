// horse.c

#include <npc.h>

void create()
{
        set_name("����", ({ "wild horse","horse" }) );
        set_race("beast");
        set("verbs", ({ "bite", "crash" }) );
        set_stat_maximum("gin", 40);
        advance_stat("hp",50);
          set_attr("cps", 2);
        set("age", 3);
        set("long", "�@�����ͪ��°��A���C���Y�Y�ۯ�C\n");
        setup();
}

