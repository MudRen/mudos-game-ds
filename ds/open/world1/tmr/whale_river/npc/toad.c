
#include <npc.h>

void create()
{
        set_name("小蟾蜍", ({"small toad","toad" }) );
        set_race("beast");
        set("age", 1);
        set_stat_maximum("gin", 10);
        set_stat_maximum("hp", 10);
        set_attr("str",1);
        set_attr("cps",1);
        set_attr("con",1);
        set_attr("dex",1);        
        set("long", "一隻十分醜陋的小蟾蜍，正在湖岸跳來跳去。\n");
        set("chat_chance", 8);
        set("chat_msg", ({
                "小蟾蜍跳了過來，又跳了過去....\n",
        }) );

        setup();
}

