#include <npc.h>

void create()
{
        set_name("�j���T", ({ "big shark","shark" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set("age", 20);
        set("long", "�@�����y�L�Q���j���T�A�����L�ءA���c�����a�n�ۧA�A���G�n��A�Y�F�C\n");
        set("attitude", "aggressive");
        setup();
        set_level(15);
        carry_object(__DIR__"obj/shark-armor");
}

