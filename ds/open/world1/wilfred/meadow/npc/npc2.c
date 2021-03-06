// 你突然發一陣怪聲『哞∼∼∼∼∼∼∼∼∼∼∼∼』  wilfred@DS
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("牛博士", ({ "cow master","master" }) );
  set("gender", "男性" );
  set("long",@LONG
『牛博士』，本名胡牛，自小與草原為伍，過著隱居的生活，對牧
牛極有心得。數十年如一日，雖身處中原，卻從來不過問武林之事
，放身原野中，牧牛自樂。胡牛年逾七十，白髮蒼蒼，仍紅光滿面
，身體健壯，手足輕捷，自是有湛深的內功修為維持身體年輕。西
域人及漠北牧人為抵抗早晚極大的溫差，各族皆向其長老學習西域
特有之內功心法，胡牛日常與其接觸，自是學到不少氣轉運行的要
旨，雖然拳腳功夫未得名家傳授，但僅著一套自行摸索出的牯牛拳
法，以及內功的修為，實可列武林好手之流。
LONG
);
  set("age",72);
  set("level",40);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("exert momo-ken") :),
"牛博士看著遠方，眉頭微蹙，似乎有些煩惱。\n",
(: command("hmm") :),
}));

  set_skill("momo-ken",100);
  set_skill("unarmed",80);
  set_skill("parry",40);
  set_skill("dodge",30);
  map_skill("unarmed","momo-ken");
  set("Merits/wit",2);
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  set_living_name("cow_master");
  add_money("gold", 5 );
  carry_object(__DIR__"eq/eq1")->wear();
}

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"牯牛") != -1)
  {
    command("hmm");
    command("say 我一生牧牛，甚麼黃牛水牛公牛都見過，其不同品種的優點可說是各擅勝場。");
    command("say 牯牛本身耐寒，適合漠北的氣候，所以這片草原上放牧的全是牯牛。");
  }
  if(strsrch(str,"幫忙") !=-1 || strsrch(str,"煩惱") != -1)
  {
    command("say 我定期要售與磬龍城一批牯牛以備軍用，但牯牛生性不喜受拘束，因此集結牯牛的工作總令我煩惱。");
    command("say 如果你能幫我趕五隻牯牛，趕到帳篷北邊的柵欄裡，自有酬謝。");
    command("say 至於方法嘛.....");
  }
  if(strsrch(str,"方法") != -1)
  {
    command("say 嗯.... 方法其實很簡單。");
    command("say 把牛拉到指定方向去，例如(pull east)，拉到柵欄裡再栓在柱子上(lock_up)");
    command("say 這樣就行了。");
  }

  return;
}

void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   message("world:world1:vision",
HIG"\n【小道消息】名馳漠北的『牛博士』胡牛被"+ob->name(1)+"殺死了。\n\n"NOR,users());

   tell_object(ob,HIW"[你得到額外的 1 點聲望]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}


