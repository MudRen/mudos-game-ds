#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
set_name(HIR"紅包"HIW"老人"NOR,({"new year oldman","oldman","man"}));
        set("long","一個很有錢的老人，但是卻好像有什麼心事..\n",);
        set("gender","男性");
        set("race", "人類");
        set("age", 70);
        set("title",HIY"恭喜發財"NOR);
        set("no_fight", 1);
        set("sell_list",([
                __DIR__"cracker" : 600,
        ]) );
        set("chat_chance", 25);
        set("chat_actions", ({
        (:command,"say ..真想看看年獸的鬚...聽說質感非常好。":),
        (:command,"say 祝大家新年快樂，恭喜發財！":),
        (:command,"say 祝「夢幻七域」發展順利！":),
        (:command,"cong":),
        (:command,"smile":),}) );
     set("inquiry/收集","我最喜歡收集年獸的鬚了，很有韌性。只可惜牠不常出現。\n"NOR);       set("inquiry/鬚","年獸的鬚只要拿鞭炮嚇嚇牠，就會掉鬚了，不過我不敢去...因為他看起來很凶\n"NOR);
//   set("inquiry/鞭炮","我有很多鞭炮，要幫我的話可以跟我說(say 我要鞭炮)。\n"NOR);
     setup();
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

void greeting()

{
        command("say 快來買鞭炮吧！");
        return;
}


/*
void relay_say(object me, string str)
{
   object mob,obj,room;
   mob = this_object();
   obj = new("/u/c/coffee/game/newyear/cracker");

   if(strsrch(str,"我要鞭炮") != -1)
   {
      if(!me->query_temp("take_ok"))
      {
         message_vision(NOR"$N"HIW"拿了一個"HIR"鞭炮"HIW"給$n，並且為$n加油打氣！！\n"NOR,mob,me);
         me->set_temp("take_ok",1);
         obj->move(me);
         call_out("check",300,me);
      }
      else { message_vision("$N對著$n說:你不是剛剛才拿過..= =？等會兒再來吧...\n",mob,me); }
   }
   return;
}

void check(object me)
{
  me->delete_temp("take_ok");
  return;
}
*/
int accept_object(object me, object ob)
{
   object obj,item;
   obj = this_object();
   item = new("/u/c/coffee/game/newyear/red-packet");

   if(ob->query("id") == "monster-beard")
   {
 message_vision("$N說:這是年獸的鬚...你怎麼拿到它的？！\n",obj);  
 message_vision("$N說:"HIG"趁牠不注意的時候拿鞭炮炸牠的..牠被嚇到就掉了一根鬚。\n"NOR,me);  message_vision("$N老夫實在是太佩服您了...\n",obj);
message_vision("$N說:祝你新年快樂啊！對了..感謝您替老夫拿到年獸鬚..老夫就送你一個紅包討個吉利吧！\n",obj);  
     message_vision("$N拿出一個"+item->name()+"給$n，並且祝$n新年快樂！\n"NOR,obj,me);

      item->move(me);
      if(!item->can_move(me))
      {
         write("你拿不動，東西掉在地上了。");
         item->move(environment(me));
      }
    destruct(ob);  
    return 1;
  }
  else
  { 
     message_vision("$N搖搖頭說:我不要"+ob->name()+"拉！\n",obj);
     return notify_fail("");  }
 return 1;
}


