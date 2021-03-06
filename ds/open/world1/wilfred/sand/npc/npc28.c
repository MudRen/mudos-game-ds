#include <ansi.h>
#include <path.h>
inherit NPC;

int quest();

void create()
{
  set_name("書僮", ({ "servant" }) );
  set("gender", "男性" );
  set("long",@LONG
他是天機老人的孫子，同時也充當書僮的工作，自小耳濡目染，對天機術產
生了莫大的興趣，因此通常他都叫他的袓父天機老人為『師父』。
LONG
);      
  set("age",7);
  set("level",3);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
(: command("sigh") :),
(: command("inn") :),
(: quest :),
}));

  set("chat_chance_combat", 30 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  carry_object(__DIR__"eq/eq2")->wear();
  set("mirror_number",5);
  call_out("re_quest",900);
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

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N正在仔細的研究易經的內容。",ob);
  else command("say 師父老是不準我動他的書櫃，但我也想學天機術呀...");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object(), obj;
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"天機術") !=-1)
    command("say 就是能夠上觀天意，下知地理的一門學問呀，研究天機術需要一本易經來配合，但師父不準我拿他的書呀....");
  if(strsrch(str,"易經") !=-1)
    command("say 易經是自古以來最偉大的鉅著啊.. 易經所言均為天地至理，萬物相生相剋，四時節氣，都脫不了易經所闡述之範疇。");
  if(strsrch(str,"師父") !=-1)
  {
    command("say 我師父－－同時也我袓父，天機老人，上天下地無所不知無所不曉呢，我最崇拜他了。");
    command("say 你要找我師父嗎？他現在可能在靜心亭或是湖心小屋那裡，你去那裡找找看吧。");
    command("say 咦... 不對，他也有可能去本因坊哥哥那裡了");
    command("say 嗯，或者我師父己經在回家的路上了，我不確定啦.... 唉唷! 幹嘛打我頭啊你∼∼");
  }
  if(strsrch(str,"棋盤") !=-1 )
  {
    if(ob->query_temp("item_give"))
      command("say 棋盤己經給"+ob->query_temp("item_give_who")+"了，他說要幫我拿去還，真是個好人。");
    else
    {
      command("say 喔，這是本因坊哥哥的棋盤，上次師父跟他借去，忘了還，你幫我拿去還吧。");
      new(__DIR__"obj/obj2")->move(ob);
      command("give "+me->query("id")+" chessboard");
      ob->set_temp("item_give",1);
      ob->set_temp("item_give_who",me->query("name"));
    }
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 師父說不能亂收別人的東西，"+ob->name(1)+"還你∼∼\n");
    command("give " +who->query("id")+ " " +ob->query("id"));
    return 1;
  }
  if(ob->query("id") != "easy book" )
  {
    command("say 這是什麼呀？師父說不能亂收別人的東西");
    write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say 我己經有一本了∼∼∼不用了∼謝謝你∼∼。");
    return notify_fail("");
  }
  destruct(ob);
  command("thank " +who->query("id"));
  command("say 你真好，這樣我就可以研究天機術了∼∼對了"+RANK_D->query_respect(who)+"，這是我的寶物，上次在黃沙道上撿到的，送你∼∼");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

