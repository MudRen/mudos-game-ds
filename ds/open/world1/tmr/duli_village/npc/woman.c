#include <npc.h>

inherit F_VILLAGER;

void create()
{
         set_name("村婦", ({"woman" }) );
        set_race("human");
        set("age", 30);
        set("long", "一個平凡的村婦，正忙著清掃房子內庭。\n");
        setup();
}

int accept_fight(object ob)
{
        return 0;
}

