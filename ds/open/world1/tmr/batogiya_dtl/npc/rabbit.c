// rabbit.c

#include <npc.h>

void create()
{
    set_name("����", ({ "wild rabbit","rabbit" }) );
    set_race("beast");
    set("long", "�@���Ⲵ�F�ʦ��������ߡA���b��a�����۸����a���A�C\n");
    set("verbs", ({ "bite", "crash"}) );

    set_attr("cps", 2);

    set("age", 1);

    setup();

}
