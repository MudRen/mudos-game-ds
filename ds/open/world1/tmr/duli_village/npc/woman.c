#include <npc.h>

inherit F_VILLAGER;

void create()
{
         set_name("����", ({"woman" }) );
        set_race("human");
        set("age", 30);
        set("long", "�@�ӥ��Z�������A�����۲M���Фl���x�C\n");
        setup();
}

int accept_fight(object ob)
{
        return 0;
}

