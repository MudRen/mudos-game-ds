#include <npc.h>

void create()
{
        set_name("���ɦǺ�", ({ "crazy bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 5);
        set("long", "�@���Ⲵ�o�����Ǻ��A�n���n��A�Y�F�U�h�@�ˡC\n");
        setup();
        set_stat_maximum("hp",450);
        carry_object(__DIR__"obj/bear-paw");
}

