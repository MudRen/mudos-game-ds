#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("鏡魔", ({ "mirror demon","demon" }) );
  set("gender", "男性" );
  set("long",@LONG
這是一個由鏡子化成的小魔鬼, 你可以像他打探一些小消息ㄡ!!
LONG
);      
  set("age",10);
  set("level",50);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"鏡魔邪邪的笑著...\n",
(: command("say 您可以問我一些事情ㄡ...^^") :),
}));
void init()
{
  add_action("do_say","say");
}

int do_say(string str)
{
  if(!str) str = "...";
  if(strsrch(str,"鏡魔啊鏡魔, 誰是ds最帥的人?") !=-1)
    command("say 當然是who->query("id")大人您最有個性, 最有智慧, 您的恩惠如滔滔江河永流不絕, 您的志氣比天高, 您真是民族的英雄, 國家的棟樑!!", who);
  if(strsrch(str,"鏡魔啊鏡魔, 誰是ds最黑的人?") !=-1)
    command("say 當然是烏漆嗎黑(Uchimaha)大人最黑lo...!!");
  if(strsrch(str,"鏡魔啊鏡魔, 誰是ds最吵的人?") !=-1)
    command("say 這還用說嗎...當然是不點(Dkfum)蛋餅犬話最多lo...^^");
  }
  return 0;
}
void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  switch(random(3))
  {
    case 0 : command("say 問我誰是ds最帥的人吧!!");
             break;
    case 1 : command("say 問我誰是ds最黑的人吧!!");
             break;
    case 2 : command("say 問我誰是ds最吵的人吧!!");
             break;
  }
  return;
}
