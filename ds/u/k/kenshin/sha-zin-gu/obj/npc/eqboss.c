#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("商人", ({ "boss" }) );
        set("gender", "女性" );
        set("level",1);
        set("age", 22); 
        set("title",HIY"暇日谷"NOR);        set("long", 
            "暇日谷內防具舖的女老闆,聽說舖內的防具都是上等貨，\n"            "一定要購買(buy)了才知道!!\n"                        );
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
             "鐵匠說:來喔!!我們賣的防具是夢幻七域裡最便宜的喔!!\n",
                       }));
        set("sell_list",([    
                                                  
                 __DIR__"eq/mask"      : 30,     
                 __DIR__"eq/boots"      : 30,   
                 __DIR__"eq/waist"     : 30, 
                 __DIR__"eq/surcoat"     : 30,  
                  
                                     ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

