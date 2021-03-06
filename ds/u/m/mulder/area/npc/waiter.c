#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("服務生", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","這位正服務生對你微笑。\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "服務生");
        set("sell_list",([
	    __DIR__"obj/chicken_leg" : 30,
                __DIR__"obj/dumpling" : 30,
	    ALWAYS+"torch" : 50,
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
                        say( "服務生笑咪咪地說道﹕這位" + RANK_D->query_respect(ob) + "﹐進來喝買些食物﹐歇歇腿吧。\n");
                        break;
                case 1:
                        say( "服務生﹐說道﹕這位" + RANK_D->query_respect(ob) + "﹐請進請進。\n");
                        break;
                case 2:
                        say( "服務生說道﹕這位" + RANK_D->query_respect(ob) + "﹐歡迎光臨，新彼得旅店！。\n");
        }
}
