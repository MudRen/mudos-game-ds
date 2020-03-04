#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("小販", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long","這位小販正笑咪咪地整理他的東西﹐還不時朝你這裡望了望。\n");
        set("level",1);
        set("attitude", "friendly");
        set("sell_list",([
                __DIR__"obj/dumpling" : 8,
                __DIR__"obj/water" : 10,
                ALWAYS+"torch" : 5,
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

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "小販對你說道﹕這位" + RANK_D->query_respect(ob) + "﹐要不要來一個熱騰騰的肉包子阿?\n");
                        break;
               
        }
}

