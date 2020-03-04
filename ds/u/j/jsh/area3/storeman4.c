#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("老王", ({ "old wang", "wang" }) );
        set("long",
                "武器攤的老闆，做出來的武器品質是步靈城裡保正的。\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
"老王大聲喊叫:各式武器喔 ~ ~\n", 
"老王拿著手中的鐵鎚敲打著燒紅的鐵塊，準備做下一樣武器了\n",
(: command,"come" :),
(: command,"say 這位客人，您想要點什麼..^^~" :),
}));
        set("sell_list",([
__DIR__"iron_sword": 5, 
__DIR__"iron_blade": 5, 
__DIR__"iron_dagger": 5,
__DIR__"iron_axe": 5,
__DIR__"iron_whip": 5,
__DIR__"iron_staff": 5, 
__DIR__"iron_fist": 5, 
__DIR__"iron_bow": 5,  
__DIR__"iron_pike": 5, 

]));
        set("level", 20);
        set("no_fight",1);
        set("age", 39);
        set("storeroom", __DIR__"/store4.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

