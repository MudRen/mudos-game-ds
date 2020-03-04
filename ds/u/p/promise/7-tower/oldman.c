#include <ansi.h>
inherit NPC;

void create()
{
  set_name("老者", ({ "oldman" }) );
  set("gender", "男性" );
  set("long",@LONG

曾經在武林上有著一席之地，人稱劍星的白仁霜，但為什麼此時
會落的如此的落魄，衣不著杉不整的，想必有著不為人知的往事
吧。

LONG
);
  set("age",61);
  set("level",1);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"老者不停的嘆氣，似乎有著說不完的往事。\n",
(: command("stare") :),
}));
  set("talk_reply","這位朋友，想知道啥請與我交談(Say)！\n");
  setup();
  add_money("coin",2000+random(1000));
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
  object player = this_player();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"往事") != -1)
  {
    command("hmm");
    command("say 都怪我一時大意，敗在他手中。");
    command("sigh");
  }
  if(strsrch(str,"他") !=-1)
  {
    command("say 他？哪個他，是我戰敗的那個人？");
    
  }
  if(strsrch(str,"是的") != -1)
  {
    command("say 他就是此塔的塔主，人稱耄妖邪的殘似");
    command("say 當年要不是我太大意，太看輕他的實力，我也不會落得如此的下場。");
    command("say 終生被關在此塔裡。");
    command("say 這位朋友，你願意幫我忙嗎？");
  }
  if(strsrch(str,"願意") != -1)
  {
    command("say 那我給你兩道選擇，第一殺了我讓我解脫，第二救我出去！");
    command("say 如果你選擇前者，現在就動手吧(kill oldman)。");
    command("say 倘若是後者，那我在此地等你，順便幫我取得患十解纏丸！！");
    
  }
  if(strsrch(str,"患十解纏丸") != -1)
  {
    command("say 這個老賊不但軟禁我，還逼我吃下此毒藥！");
    command("say 聽說是要在服一粒一樣的藥物，才能解毒。");
    command("say 快！我在這兒等你，快去吧！");
    command("say 為了表達我的心意，我運用殘存的內力，送你到此亞空間最內部！！");
    message_vision(HIW"\n只見老者運起內力，揮了一掌朝著$N去，$N消失無蹤！！"NOR);
    player->move(__DIR__"4f_7");
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
     message("world:world1:vision","\n"HIY"【秦假仙快報】："HIM"十惡不赦的"+ob->query("name")+"因錯殺老者，結果被老者的� 魂魄給擊斃了！！\n\n"NOR,users());
           ob->die();
                     ::die();
        return;
}

