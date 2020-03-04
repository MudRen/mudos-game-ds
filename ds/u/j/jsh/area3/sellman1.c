#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("採藥老人", ({ "pick medicine-man", "man" }) );
        set("long",
                "一位以山而活的老人，常攀上紫陽山去採集藥材。\n"
                        ); 
        set("chat_chance",4);
        set("chat_msg",({ 
"採藥老人高聲喊道: 上等藥材煉製而成的藥丸ㄛ ~ ~\n",
(: command,"sweat" :),(: command,"smile" :),
(: command,"say 補血 補氣 補神 的藥丸" :),(: command,"sigh" :),
}));
        set("sell_list",([
__DIR__"hp-pill": 10,
__DIR__"ap-pill": 10,
__DIR__"mp-pill": 10,
]));



        set("level", 20);
        set("no_fight",1);
        set("age", 60);
        set("storeroom", __DIR__"/store1.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

