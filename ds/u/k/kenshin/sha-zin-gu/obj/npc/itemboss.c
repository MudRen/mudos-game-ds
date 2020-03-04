#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("道具商人", ({ "item boss","boss" }) );
        set("gender", "男性" );
        set("level",1);
        set("age", 44); 
        set("title",HIY"暇日谷"NOR);        
        set("long", 
            "暇日谷內道具舖的老闆,聽說舖內的道具都是上等貨，\n"            "一定要購買(buy)了才知道!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "道具商人說:來喔!!我們賣的道具是夢幻七域裡最便宜的喔!!\n",
                       }));
        set("sell_list",([    
                                                  
                 __DIR__"item/seal"      : 99,     
                 __DIR__"item/pearl"      : 99,   
                 __DIR__"item/superbag"     : 99, 
                 
                  
                                     ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

