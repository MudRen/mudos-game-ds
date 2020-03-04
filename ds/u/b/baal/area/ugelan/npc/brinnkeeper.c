#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "帕哈夫", ({ "pahafou innkeeper","innkeeper"}));
        set("long", "一個賊眼兮兮的旅店老闆，一雙老鼠眼老是骨嚕骨嚕的在你的
口袋打轉...\n\n"
                      + "  看存貨請用 <list> \n"
                     + "  要買東西用 <buy 物品> <buy 數量 物品> \n\n");
           set("level",5);
        set("title","旅店老闆");
        set("gender", "男性");
        set("race", "人類");
        set("age", 54);
        set("no_fight",1);
        set("combat_exp",500);         //戰熟(約在mob level的100倍左右為宜)
//      set("env/wimpy", 20);           //逃跑wimpy (20%)
        set("evil",50);                //邪惡度 20 (正的表邪惡, 負表善良)
        set("attitude", "peaceful");   //溫和的 NPC。
                   //注意. 要設定貨品清單
        set("sell_list",([
      __DIR__"obj/gmsoup" : 25,
          __DIR__"obj/hotwater" : 50,
        ]) );
           setup();
          add_money("coin", 120);           //帶的錢
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
               say("帕哈夫說道：口黑口黑口黑∼∼這位" + RANK_D->query_respect(ob)
                                + "﹐在長途旅行後...您要不要來點肉羹填填肚子...？\n");
               break;
           case 1:
               say( "帕哈夫邊搓著手邊說著：呦∼∼∼這位" + RANK_D->query_respect(ob)
                                + "﹐稀客稀客...裡面坐啊。\n");
               break;
           case 2:
               say("帕哈夫眼睛叮著你的口袋賊兮兮的說：這位" + RANK_D->query_respect(ob)
                                + "﹐你要些什麼啊...\n");
               break;
        }
}


