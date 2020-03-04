//米特 mite.c -Tmr

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name( "藥販" , ({ "medication seller" , "seller"}) );
        set_race("human");
        set("title","死亡之森");
        set("gender", "male");
        set("age", 40 );
        set("long",@long
　　在你眼前的這位藥販長的五短身材，滿臉已經化膿或是結瘡的痘子，長
相實在是醜陋的讓人不敢恭維。
long
);

          set("merchandise", ([
                 __DIR__"obj/pellet": 250,
                  __DIR__"obj/pellet": 250,
                  __DIR__"obj/jerk": 250,
          ]));




        set("chat_chance", 5);
        set("chat_msg", ({
                "藥販嘶啞地嗓子叫賣著：「這有靈驗無比的藥草，有興趣來看看唷！」 \n",
                "藥販背著沉重的藥箱，嘴裡不知在喃喃自語什麼...\n",
        }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}
