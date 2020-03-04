#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(HIC "月下老人"NOR, ({ "match-maker"}));
        set("long", "他是中國相傳至今的一位神君，專幫人牽紅線\n"
                    "，讓有情人終成眷屬，他看起來白髯至胸，和\n"
                    "藹可親。\n"
           );
        set("level",1);
        set("gender", "男性");
        set("race", "人類");
        set("age", 200);
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set("attitude", "peaceful");   //溫和的 NPC。
        set("no_fight",1);
        set("talk_reply","你要我幫你牽紅線嗎？");
        set("sell_list",([
        __DIR__"obj/choco" : 10,
        ]) );
        setup();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
           case 0:
               say("月下老人說道：這位" + RANK_D->query_respect(ob)
                                + "﹐來買些情人巧克力吧。\n");
               break;
           case 1:
               say("月下老人說道﹕這位" + RANK_D->query_respect(ob)
                                + "﹐買束花送送情人吧。\n");
               break;
        }
}
