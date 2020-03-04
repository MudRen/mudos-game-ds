#include <ansi.h>
#include <command.h>
inherit NPC;
int do_divorce2(string index);
object ppl2, ppl1;

void create()
{
  set_name(HIM"粉紅佳人"NOR, ({"pretty girl","girl"} ));
  set("gender", "女性" );
  set("age", 18);
  set("long",@LONG
(buy house for 人)
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say 來喔~~不景氣, 房地產大下跌喔~~" :),
(: command,"giggle" :),
(: command,"say 大家都要存些不動產好過年!"  :),
(: command,"come"  :),
     }));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  setup();
}

void init()
{
  seteuid(getuid(environment()));
  if(!userp(this_player())) return;
  add_action("do_buy","buy");
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
  add_action("do_name",({"name"}) );
}
int do_buy(string str)
{
  object target, temp, ob = this_object(), me = this_player();
  if(str != "house") return notify_fail("朋友..你想買啥東西阿?\n");
  if(query("divorcing")) return notify_fail("她似乎正在忙.\n");

  message_vision(HIW"$N慎重地說：我想買一棟房子跟Honey過冬說...@@\n",me);
  if(me->query("bank/past") < 500000)
  {
    command("smile");
    command("say 一棟房子需50兩黃金喔@@");
    return 1;
  }
  target = me->query("marry_id");
  if(!target)
  {
    command("peer");
    command("say Sorry...Did you have marry mate??");
    return 1;
  }
  if(userp(target) && environment(target) == environment(ob))
  {
    ppl1 = me;
    ppl2 = target; 
    set("divorcing",1);
    command("hmm");
    call_out("do_divorce1",3);
    return 1;
  }

  command("say 朋友..你不覺得這種事要先徵求伴侶的同意嗎?");
  command("snicker");
  return 1;
}

void do_divorce1()
{
  object ob = this_object();
  string index;

  if(environment(ppl1) != environment(ob))
  {
    command("flop");
    command("say 金主怎麼跑掉ㄌ？");
    delete("divorcing");
    delete("asking");
    return;
  }
  if(environment(ppl2) != environment(ob))
  {
    command("??");
    command("say 朋友, 你的伴侶勒？");
    delete("divorcing");
    delete("asking");
    return;
  }
  command("smile "+ppl2->query("id"));
  command("say 您的伴侶想要買一棟房子...您意下如何ㄋ？");
  tell_object(ppl2,"您Honey申請房子一棟，請問你同意嗎？ [yes/no]\n"NOR);
  set("asking",1);
  return;
}
int do_yes()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("n");
    return 1;
  }
  return 0;
}
int do_name(string id)
{
  if(this_player() == ppl1 && query("asking2"))
  { 
   if(file_size("/open/world1/kkeenn/marry/house/"+id+".c")>0) 
      return notify_fail("Sorry...這個ＩＤ已經有人用過了...\n");
    ppl1->set("marryhouse",id);
    ppl2->set("marryhouse",id);
    write_file("/open/world1/kkeenn/marry/house/" + id + ".c", @ROOM_CODE
inherit ROOM;
void create()
{
        set("short", "愛之屋");
        set("long", "這是一間透天的小屋子。\n");
        setup();
        replace_program(ROOM);
}
ROOM_CODE
        );
    delete("asking2");    
    return 1;
  }
  return 0;
}
int do_divorce2(string index)
{
  object ob = this_object();
  object obj1,obj2;
  string marryhouse;
  if(index == "y")
  {
    message_vision(HIR"\n[$N高興的說: 真的嗎！我不可能反對的啦~~]\n\n"NOR,ppl2);
    command("say 太好了！那就先收錢50兩黃金喔！");
    if(ppl1->query("bank/past") < 500000)
    {
      command("say 那關於申請費的事....");
      command("flop");
      command("ack");
      command("say 原來是窮光蛋?! 本小姐看走眼了，既然如此這件事情就算了吧。");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(environment(ppl1) != environment(ob))
    {
      command("flop");
      command("say 金主跑了，這件事情就當沒提過吧。");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    delete("divorcing");
    delete("asking");
    set("asking2",1);
    tell_object(ppl1,"請輸入一個id[name id]\n"NOR);  
    return 1;
  }
  message_vision(HIC"\n[$N堅決的搖了搖頭]\n\n"NOR,ppl2);
  command("say ㄟ？您的伴侶不同意ㄟ，你們還是先回去商量好了...");
  delete("divorcing");
  delete("asking");
  return 1;
}
void reset()
{
  delete("divorcing");
  delete("asking");
  delete("asking2");
  command("say 你來的不巧，今天公休日，想離婚明天趁早。");
}
