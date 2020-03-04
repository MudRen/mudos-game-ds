// man.c

#include <npc.h>

inherit F_VILLAGER;

void create()
{
         set_name("漁民", ({ "fisherman","man" }) );
        set_race("human");
        set("age", 40);
        set("long", "一個中年漁民，身上背著一副魚網，看起來並沒有特別之處。\n");
        setup();
        carry_money("coin", 50);
}

int accept_fight(object ob)
{
        do_chat("漁民瞪著眼睛說道：「我還得要去捕魚養家，你別逗了。」\n");
        return 0;
}

