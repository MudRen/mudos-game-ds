// fisher.c 釣客

#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("釣客", ({"fisher" }) );
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 20);
        set_stat_maximum("hp", 20);
        set("long", "一個戴著斗笠，正在釣魚的釣客。\n");
        set("chat_chance", 8);
        set("chat_msg", ({
                "釣客站起來望了望湖面，喃喃自語道：「不知那條湖怪會不會再現身...」\n",
                "釣客伸手擦了擦頭上的汗...\n",
                "釣客轉過頭來望了你一眼，又轉回去繼續坐著釣魚。\n",
        }) );

        setup();
        carry_money("coin", 10);
        carry_object(__DIR__"obj/rod")->wield();
        carry_object(__DIR__"obj/hat")->wear();
}

