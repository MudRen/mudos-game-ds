#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("湯哥"NOR, ({ "soup seller", "seller" }) );
        set("long",
                "賣湯的小販，採自紫陽山上的白蛇煮成。\n"
                        ); 
        set("chat_chance",10);
        set("chat_msg",({ 
(: command,"sweat" :),
(: command,"say 喝了這種湯對身體很好的 !" :), 
(: command,"say 客官..來一碗吧!" :),}));
        set("sell_list",([
__DIR__"soup": 5,
]));
        set("level", 20);
        set("no_fight",1);
        set("age", 42);
        set("storeroom", __DIR__"/store2.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

