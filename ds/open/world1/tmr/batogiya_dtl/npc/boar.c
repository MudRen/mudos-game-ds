#include <npc.h>

void create()
{
    set_name("����", ({ "wild boar", "boar" }) );
    set_race("beast");
    set("long", "�@������۷�Τj�����ޡA���b�μL�b�a�W���ӫ��h�C\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("con", 2);

    set("age", 1);

    setup();

        advance_stat("gin", 30);
        advance_stat("hp", 50);
    set_level(2);
}
