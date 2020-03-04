#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("店小二", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","這位店小二正笑咪咪地忙著﹐還不時拿起掛在脖子上的抹布擦臉。\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("sell_list",([
                __DIR__"obj/manto" : 8,
                __DIR__"obj/bag" : 10,
                __DIR__"obj/soup":10,
                ALWAYS+"torch" : 5,

                ALWAYS+"newspaper" : 10,
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
                        say( "店小二笑咪咪地說道﹕這位" + RANK_D->query_respect(ob) + "﹐進來喝杯茶﹐歇歇腿吧。\n");

                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手﹐說道﹕這位" + RANK_D->query_respect(ob) + "﹐請進請進。\n");
                        break;
                case 2:
                        say( "店小二說道﹕這位" + RANK_D->query_respect(ob) + "﹐進來喝幾盅小店的紅酒吧﹐這幾天才從窖子裡開封的喲。\n");
                        break;
        }
}


