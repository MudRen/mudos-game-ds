#include <ansi.h>

inherit NPC;
void create()
{
        set_name("小孩",({ "child" }) ); 
        set("long","一個居住在獵狐村的小孩，整天嘻戲玩樂，不過似乎有著偉\n"
                   "大的夢想！\n");
        set("race","human");
        set("gender", "男性");
        set("title", HIR"獵狐村"NOR);
        set("age",4+random(5));
        set("level",5+random(5));
        set("attitude","friendly");
        set_skill("dodge",15);
        set_skill("unarmed",15);
        set_skill("parry",15);
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("say 我一定要殺了九尾，成為村子的英雄！") :),
                          (:command("addoil child"):),
        }));

        setup();
        add_money("coin",200);           
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
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
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"夢想") != -1)
  { 
    command("oh"); 
    command("say 我的夢想就是能殺了那隻九尾！"); 
  }  
return;
}

