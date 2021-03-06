#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("聖誕小女孩", ({ "christmas girl", "girl" }) );
        set("gender", "女性" );
        set("age", 14);
        set("long","這是一位長得非常可愛的小女孩，正提著個籃子，在沿街叫賣著東西。\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("sell_list",([
            "/u/t/tmr/game/2006_c/order": 1, // 2006聖誕活動
            "/u/t/tmr/game/2006_c/cannon1": 1, // 2006聖誕活動
            "/u/t/tmr/game/2006_c/cannon2": 1, // 2006聖誕活動
            "/u/t/tmr/game/2006_c/cannon3": 1, // 2006聖誕活動
                "/u/t/tmr/game/2006_c/cannon0": 3, // 2006聖誕活動
                 "/u/t/tmr/game/2006_c/cannon00": 100, // 2006聖誕活動

       ]) );
        set("no_kill",1);
        setup();
        carry_object(__DIR__"eq/hat")->wear();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/gloves")->wear();
        carry_object(__DIR__"eq/boots")->wear();
        carry_object(__DIR__"eq/beard")->wear();
        carry_object(__DIR__"eq/waist")->wear();
        carry_object(__DIR__"eq/pants")->wear();
}


void init()
{       
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

