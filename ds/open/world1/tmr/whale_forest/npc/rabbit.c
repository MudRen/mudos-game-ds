// rabbit.c

#include <npc.h>

void create()
{
        set_name("����", ({ "wild rabbit","rabbit" }) );
        set_race("beast");
        set_stat_maximum("gin", 30);
        set("verbs", ({ "bite", "crash"}) );
        advance_stat("hp",50);
        set("age", 1);
          set_attr("cps", 2);
        set("long", "�@���Ⲵ�F�ʦ��������ߡA���b��a�����۸����a���A�C\n");
        setup();
}


