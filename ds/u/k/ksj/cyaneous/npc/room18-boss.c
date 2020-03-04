#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("老闆", ({ "boss", "boss" }) );
        set("long","一位平易近人的老闆，在當地是相當有名的。\n");  
        set("chat_chance",10);
        set("sell_list",([
__DIR__"obj/red-wine": 10, 
]));
        set("level", 1);
        set("no_fight",1);
        set("age", 45);
        set("storeroom", __DIR__"/store6.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}


