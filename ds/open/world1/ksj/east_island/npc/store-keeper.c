#include <path.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("五衛門", ({"store keeper","keeper"}));
        set("long",
                "一位矮矮胖胖的商人，脖子上掛了一條粗重的金鏈，手上拿著長煙斗\n"
                "，不時地吸著煙巡視店中的典當物品。\n");
        set("level", 20);
        set("no_fight",1);
        set("age", 43);
        set("storeroom", __DIR__"shop.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
}
