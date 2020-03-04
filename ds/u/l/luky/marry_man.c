#include <ansi.h>
inherit NPC;

int do_action2(string index);
object girl, boy;

void create()
{
  set_name("王媒婆", ({ "mrs. wang","wang" }) );
  set("gender", "女性" );
  set("age", 52);
  set("long",@LONG

她是一位專門為人說媒的人，所有有關結婚喜慶的事，只要找她辦包準辦到好。

如果想結婚，請將您的準新娘子帶到她跟前來，輸入 marry <對方的 id>
如得對方允可，此事便圓滿達成，媒人會收您 10000 枚古幣 (從銀行扣)
當紅包，並施放喜慶煙火公告天下。

<請注意> 未成年如想說媒，媒人婆可是不會理你的
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say 男大當婚，女大當嫁" :),
  (: command,"smile" :),
  (: command,"say 世間多少紅塵夢，千里福緣一線牽" :),
  (: command,"hoho" :),
}));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  set("no_fight",1);
  setup();
}

void init()
{
  if(!userp(this_player())) return;
  add_action("do_marry","marry");

  // 似乎不能讓作 girl->input_to() 的動作 why ?
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
}

int do_marry(string str)
{
  object target, temp, ob = this_object(), me = this_player();

  if(query("action")) return notify_fail("她似乎正在忙.\n");

  message_vision(HIC"$N說：$n，我想煩請您替我說一椿婚事。\n"NOR,me,ob);
  if(me->query("class1") == "凌雲寺")
  {
    command("say 您是出家人吧，等您還俗以後再說吧");
    return 1;
  }
  if(me->query("marry_id") || temp = present("marry ring",me))
  {
    command("say 你己經有配偶了喔，別三心二意的 .... ");
    return 1;
  }
  if(me->query("gender") != "男性")
  {
    command("say 自古以來皆是男方說媒，豈有女方出面說媒的道理？！");
    return 1;
  }
  if(!str)
  {
    command("say 哦？是哪家姑娘？可有她的名字麼？");
    return 1;
  }
  if(me->query("age") < 18)
  {
    command("snort");
    command("say 小弟弟，這裡不是玩耍的地方，你還是去別處玩兒吧。");
    return 1;
  }
  if(me->query("bank/past") < 10000)
  {
    command("snort");
    command("say 本媒婆不跟窮光蛋打交道。");
    write("[您銀行存款至少要有 10000 枚古幣。]\n");
    return 1;
  }
  message_vision(HIC"$N說：她名叫 "+str+" 。\n"NOR,me);

  if(!target = find_player(str))
  {
    command("hmm");
    command("say 好像沒這位姑娘喔，您請回吧。");
    return 1;
  }
// alickyuen 作出修改
  if(target->query("age") < 18)
  {
    command("snort");
    command("say 她可還是一個未成年的小姑娘耶..怎能和你...");
    return 1;
  }
  if(target->query("gender") != "女性")
  {
    command("puke");
    command("say 這位先生，如果您有同性戀的傾向，可別來找我這老太婆 ok ? -.-#");
    return 1;
  }

  if(userp(target) && environment(target) == environment(ob))
  {
    boy = me;
    girl = target; 
    set("action",1);
    command("hmm");
    call_out("do_action1",3);
    return 1;
  }

  command("say 你是說 "+str+" 嗎？帶她來這裡，我會為你說媒的。");
  command("snicker");
  return 1;
}

void do_action1()
{
  object ob = this_object();
  string index;

  if(environment(boy) != environment(ob))
  {
    command("flop");
    command("say 男方跑了，這門親事就算了。");
    delete("action");
    delete("asking");
    return;
  }
  if(environment(girl) != environment(ob))
  {
    command("??");
    command("say 這位姑娘可真害羞，一眨眼間就不見了。");
    delete("action");
    delete("asking");
    return;
  }
  command("look "+girl->query("id"));
  command("say 果然是天賜佳侶.... 待我詢問女方的意見。");
  tell_object(girl,HIC"妳願意嫁給"+boy->name(1)+"作妻子，永生永世至愛不渝嗎？ [yes/no]\n"NOR);
  set("asking",1);
  return;
}

int do_yes()
{
  if(this_player() == girl && query("asking"))
  {
    do_action2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == girl && query("asking"))
  {
    do_action2("n");
    return 1;
  }
  return 0;
}

int do_action2(string index)
{
  object ob = this_object();
  if(index == "y")
  {
    message_vision(HIR"\n[$N低下頭羞紅了臉，微微的點了點頭]\n\n"NOR,girl);
    command("say 太好了！女方答應了！真是恭喜你們！");
    if(boy->query("bank/past") < 10000)
    {
      command("say 那關於紅包的事....");
      command("flop");
      command("ack");
      command("say 原來是窮光蛋?! 老娘看走眼了，既然如此這門親事就算了吧。");
      delete("action");
      delete("asking");
      return 1;
    }
    if(environment(boy) != environment(ob))
    {
      command("flop");
      command("say 男方跑了，這門親事就算了。");
      delete("action");
      delete("asking");
      return 1;
    }
    message("system",
HIR"\n\t忽然一道煙火衝上天....\n\n"HIW"天空爆出燦爛的火花，煞是好看，只見火花排出一道字樣...\n\n\t\t"HIC"『恭喜"+boy->name(1)+"和"+girl->name(1)+"從此結為夫妻，永世恩愛不渝。』\n\n"NOR,users());

    boy->set("marry_id",girl->query("id"));
    girl->set("marry_id",boy->query("id"));

    boy->add("bank/past",-10000);
    tell_object(boy,HIG"[王媒婆跟您收了 10000 枚古幣當紅包。] 恭喜恭喜!\n"NOR);

    tell_object(boy,HIG"[王媒婆給你一只結婚戒指]\n"NOR);
    tell_object(girl,HIG"[王媒婆給你一只結婚戒指]\n"NOR);
    new("/open/always/marry_ring")->move(boy);
    new("/open/always/marry_ring")->move(girl);

  boy->save();
  girl->save();
    delete("action");
    delete("asking");
    return 1;
  }
    message_vision(HIC"\n[$N堅決的搖了搖頭]\n\n"NOR,girl);
  command("say 女方不答應耶，那就算了，不可強人所難。");
  delete("action");
  delete("asking");
  return 1;
}


void reset()
{
  delete("action");
  delete("asking");
  command("say 真對不住，今天打烊了，想結婚明天趁早。");
}

