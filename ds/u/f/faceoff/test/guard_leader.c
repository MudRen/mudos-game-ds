#include <ansi.h>
inherit NPC;
void create()
{
  set_name("王霸",({"wang bar","wang","bar"}));
  set("long",@LONG
他就是海政司眾守衛的領隊了, 為人相當高傲, 通常不輕易
和人動手, 不過由於平日執行任務太過霸道, 聽說市井之間送了
他一個外號....
LONG
    );
  set("attitude", "peaceful");
  set("age",32);
  set("gender","男性");
  set("level",31);
  set_skill("blade", 60);
  set("no_kill",1);
  set("no_fight",1);
  set("no_cast",1);
  setup();
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if(strsrch(str,"王八狗官") !=-1)
  {
      message_vision(YEL"$n愣了一愣, 隨即大怒道: 小賊找死 !!。\n"NOR,me,ob);
      ob->kill_ob(me);
  }
  else
  {
    switch(random(8))
    {
      case 1 : command("hmm");  break;
      case 2 : command("think");   break;
      case 3 : command("say 在這裡喳呼什麼? 快滾!");  break;
      case 2 : command("say 狗民還不快滾!");   break;
  }
  }
  return 1;
}
