#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("小孩", ({ "child" }) );
    set_race("human");
    set("age", 6);
    set("long", "一個住在哈哈村的小孩子，天真無邪的模樣，嘴角微微的上揚。\n");
    setup();
    carry_money("coin", 50);
}

int accept_fight(object ob)
{
    do_chat("小孩笑哈哈的說道：「哈哈！看我怎麼揍扁你。」\n");
    return 1;
}

