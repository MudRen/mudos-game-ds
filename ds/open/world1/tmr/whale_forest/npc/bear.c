// bear.c

#include <npc.h>

void create()
{
        set_name("�p�º�", ({ "small bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 5);
          set_attr("cps", 5);
        set("long", "�@�����ͪ��p�º��A���Τ��l��۾�F�A���G�b�i���Ҧ��C\n");
        setup();
	set_stat_maximum("hp",200);
}


