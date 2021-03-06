#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("小藥販", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","這位藥販正笑咪咪地忙著整理藥箱，還不時拿起掛在脖子上的抹布擦臉。\n");
        set("level",1);
        set("attitude", "friendly");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "小藥販伸長了衣袖，擦了擦臉上的汗。\n",
                "小藥販高聲喊道：「陳年狗皮膏藥，用上好老狗皮製成，保証有效∼∼」\n" 
        }) );

        set("sell_list",([
        __DIR__"obj/plaster" : 5,
         __DIR__"obj/pill3" : 5,
        TMR_PAST"bagi/npc/obj/furnace":  1,
        TMR_PAST"bagi/npc/obj/firewood": 1,
          TMR_PAST"bagi/npc/obj/firewood2": 1,
            TMR_PAST"bagi/npc/obj/firewood1": 1,
        TMR_PAST"bagi/npc/obj/roxb": 1,
        TMR_PAST"bagi/npc/obj/benth": 1,
        TMR_PAST"bagi/npc/obj/linn": 1,
        ]) );
        setup();
}

void init()
{
           add_action("do_list","list");
           add_action("do_buy","buy");
}

