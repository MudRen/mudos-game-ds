#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "辛若羽", ({ "xin reu yue","xin","yue"}));
        set("long", "她是這家布莊的老板。\n\n"
                     + "  看存貨請用 <list> \n"
                     + "  要買東西用 <buy 物品> <buy 數量 物品> \n\n");
        set("level",3);
        set("gender", "女性");
        set("race", "人類");
        set("age", 25);
        set("combat_exp",300);         //戰熟(約在mob level的100倍左右為宜)
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set_skill("dodge",10);
        set("attitude", "peaceful");   //溫和的 NPC。
        set("sell_list",([
           __DIR__"eq/boots2":10,
           __DIR__"eq/cloth2":10,
           __DIR__"eq/hat2":10,
        ]) );
        setup();
          add_money("coin", 150);           //帶的錢
          carry_object(__DIR__"eq/cloth3.c")->wear();
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
        switch( random(3) ) {
           case 0:
               say("辛若羽說道：歡迎光臨，請問這位" + RANK_D->query_respect(ob)
                                + "﹐需要些什麼呢?\n");
               break;
           case 1:
               say("辛若羽恭敬地說道﹕這位" + RANK_D->query_respect(ob)
                                + "﹐請進請進。\n");
               break;
           case 2:
               say("辛若羽說道：這位" + RANK_D->query_respect(ob)
                                + "﹐來買些防具穿穿吧。\n");
               break;
        }
}
