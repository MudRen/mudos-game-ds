#include <npc.h>

void create()
{
    set_name("�j����", ({ "big wild boar", "boar" }) );
    set_race("beast");
    set("long", "�@������۷��j�����ޡA���b�μL�b�a�W���ӫ��h�C\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("con", 7);

    set("age", 1);

    setup();

        advance_stat("gin", 50);
        advance_stat("hp", 100);
    set_level(5);
}
