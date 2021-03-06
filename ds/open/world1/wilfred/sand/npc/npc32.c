#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("張獵戶", ({ "hunter chung","chung" }) );
  set("gender", "男性" );
  set("long",@LONG
吃到飽客棧的店老闆，為人豪爽，四海皆兄弟。
LONG
);      
  set("age",32);
  set("level",25);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"張獵戶正忙著招呼店裡的客人。\n",
(: command("say 敝店的野味皆為本人親自出外狩獵而來，新鮮熱辣！哈哈哈！") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say 喝！光天化日之下竟敢打劫！納命來！") :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  carry_object(__DIR__"eq/eq9")->wear();
  set("mirror_number",4);
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
    command("say 終於如願以償了，呵呵呵，雖然紅山豬不是自己獵到的，但總算是到達目的了。\n");
  else command("say 我生平之憾只有一個，就是獵不到紅山豬，唉！");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"紅山豬") != -1)
  {
    command("sigh");
    command("say 紅山豬在黃沙嶺上才有，但此紅山豬生性機敏，每當有人靠近便逃之無蹤。");
    command("say 而且黃沙嶺上盜賊橫行，此行大為不易，唉！");
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 當我是兄弟就別送這勞什子的玩意，"+ob->name(1)+"你拿回去。");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if( ob->query("victim_name") == RED"紅山豬"NOR )
  {
    if(this_object()->query_temp("pass_quest"))
    {
      command("say 多謝你了，小店沒什麼好報答的東西，不介意的話，在這裡吃個飯再走吧。");
      return 1;
    }
    command("really " +who->query("id"));
    command("say 果真是紅山豬啊 ... 太感謝了，我有幸得此物，這給送你當作報答吧。");
    new(__DIR__"obj/obj15")->move(this_object());
    command("give " +who->query("id")+ " mirror");
    this_object()->set_temp("pass_quest",1);
    return 1;
  }
  command("say 當我是兄弟就別送這勞什子的玩意，"+ob->query("name")+"你拿回去。");
  write("["+this_object()->query("name")+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
