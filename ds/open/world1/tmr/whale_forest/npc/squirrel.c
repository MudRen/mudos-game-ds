
#include <npc.h>

void create()
{
        set_name("�Q��", ({ "squirrel" }) );
        set_race("beast");
        set("verbs", ({ "bite" }) );
        set("age", 5);
        set_attr("cps", 1);
        set_attr("str", 2);
        set_attr("con", 2);
        set("long", "�@���F�����p�Q���A���b��K����Ӭ�h�C\n");
        setup();
        set_stat_maximum("hp",50);
}

