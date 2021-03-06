#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "老王", ({ "old wang","wang"}));
        set("long", "這是一位正殷勤的招待客官的店小二。\n\n"
                      + "  看存貨請用 <list> \n"
                     + "  要買東西用 <buy 物品> <buy 數量 物品> \n\n");
           set("level",3);
        set("title","店小二");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("no_fight",1);
        set("combat_exp",2000);         //戰熟(約在mob level的100倍左右為宜)
//      set("env/wimpy", 20);           //逃跑wimpy (20%)
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set_skill("blade",40);          // 技能(自定)
        set_skill("parry",20);          //
        set_skill("dodge",30);          //
        set("attitude", "peaceful");   //溫和的 NPC。
        set("talk_reply","多買點東西就算幫了大忙囉..呵呵..");
                   //注意. 要設定貨品清單
        set("sell_list",([
      __DIR__"obj/manto" : 10,
        __DIR__"obj/water" : 10,
       __DIR__"obj/leg" : 10,
    __DIR__"obj/soup" : 10,
    __DIR__"obj/wine" : 10,
      "/open/always/torch" : 30,
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
               say("老王說道：歡迎光臨，請問這位" + RANK_D->query_respect(ob)
                                + "﹐需要些什麼呢?\n");
               break;
           case 1:
               say( "老王恭敬地說道﹕這位" + RANK_D->query_respect(ob)
                                + "﹐請進請進。\n");
               break;
           case 2:
               say("老王說道：這位" + RANK_D->query_respect(ob)
                                + "﹐進來填填肚子, 好繼續上路唷。\n");
               break;
        }
}

int talk_action(object me)	
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
 	command("say 本店每一種酒可都是酒中極品。");
 	command("say 尤其是有一種酒，名叫『燒刀子』，這種酒十分濃烈，喝了保證能讓人忘卻所有煩心之事。");
 	command("say 不過客官如果想一嚐其中奧妙，可能需要再等一些時日。");
 	command("say 因為本店僅存的幾瓶燒刀子前些日子被歹徒給劫走了。");
 	command("sigh");
 	command("say 『燒刀子』的釀造極為費時，本店已經盡力趕製了，請客官見諒。");
 	book->add_quests_note("SadSworder","『燒刀子』是一種極為濃烈的酒，為心情鬱悶，或是「為情所困」之人的最愛。");
 }
 else {
 	command("say 有位大俠每天都來這裡喝酒。");
 	command("say 可惜本店剩下的幾瓶燒刀子前陣子被一名強盜搶走了。");
 	command("think");
 	command("say 不過聽說官府已經抓到他了，可能近日之內就要問斬了吧。");
 	book->add_quests_note("SadSworder","『燒刀子』被一名大盜搶走了，而這名大盜近日將被問斬。");
 }
 return 1;
}