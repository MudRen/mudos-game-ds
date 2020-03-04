#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("店小二", ({ "waiter ccr","waiter","ccr" }) );
        set("gender", "男性" );
        set("age", 200);
        set("long","DS的老骨灰代表之一，因為Kenshin無聊，被放到這來當店小二..XD\n");
        set("level",100);
        set("attitude", "friendly");
        set("title",HIW"[DS常駐玩家NPC代表之一]"NOR);
        set("rank_info/respect", "骨灰小二");
        set("sell_list",([
                 __DIR__"item/kaoliang" : 30,
                 __DIR__"item/white-wine" :30,
                 __DIR__"item/s_wine" :30,
                 __DIR__"item/leg" :100,
        ]) );
        setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}

