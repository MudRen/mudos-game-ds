#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("工頭", ({ "work king", "king" }) );
        set("long",
                "防具攤的老闆，做出來的防具都有著極高的水平。\n"
                        );  
        set("nick",HIM"防"NOR);        set("chat_chance",10);
        set("chat_msg",({ 
"工頭拿起一件件的防具出來亮像� ~ ~\n",
(: command,"cac" :),
(: command,"say 我做的防具都是一流的 ~ ~" :),
}));
        set("sell_list",([
__DIR__"iron_helmet": 5, 
__DIR__"iron_mask": 5,
__DIR__"iron_neck": 5,
__DIR__"iron_armor": 5,
__DIR__"iron_surcoat": 5,
__DIR__"iron_hands": 5,
__DIR__"iron_cloth": 5,
__DIR__"iron_waist": 5,
__DIR__"iron_pants": 5,
__DIR__"iron_legging": 5,
__DIR__"iron_boots": 5,
__DIR__"iron_gloves": 5,
]));
        set("level", 20);
        set("no_fight",1);
        set("age", 42);
        set("storeroom", __DIR__"/store6.c");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
}

