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
        set("title","海政司");
  set("level",31);
  set_skill("blade", 60);
  setup();
 carry_object(__DIR__"../eq/cloth")->wear();
 carry_object(__DIR__"../eq/soldier_boots")->wear();
 carry_object(__DIR__"../eq/fur_waist")->wear();
 carry_object(__DIR__"../eq/cloud_ring")->wear();
 carry_object(__DIR__"../wp/steel_blade")->wield();
 carry_object(__DIR__"../obj/wang_mark");
 carry_object(__DIR__"../obj/paper");
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if(strsrch(str,"王八狗官") !=-1)
  {
    message_vision(YEL"$n愣了一愣, 隨即大怒道: 小賊找死 !!。\n"NOR,me,ob);
   message_vision(YEL"$n恨恨的說:小賊就不要讓我找到你全家....。\n"NOR,me,ob);
 command("follow "+me->query("id") );
  }
  
}
