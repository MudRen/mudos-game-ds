#include <ansi.h>
inherit NPC;
int go_way();
void create()
{
  set_name("小悠", ({ "boy yu","yu" }) );
  set("gender", "男性" );
  set("long",@LONG
    十分淘氣的一個小孩子，不知那邊來的，眼睛大大圓圓的，身上
    穿著十分質樸看來十分聰穎，令人一看喜歡上他，可是不知為何
    看到卻沒父母陪伴兩旁，也許是偷偷離家的。
LONG
);      
  set("age",12);
  set("level",10);
  set("race","human");
  set("go_home",1);
  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say 真好玩呀，到處都是沒見過的東西呢。") :),
(: command("say 爺爺就是愛嚇人，老是不讓人出來玩") :),
(: command("say 出來好些天了，不知道爺爺會不會很生氣兒") :),
"小悠坐在地上十分快樂的唱著歌，。\n",
(: command("hug") :),
(: command("say 聽說家裡附近的亂葬岡上有鬼怪，不知是什麼樣的呢，真想看看。") :),
}));

  set("talk_reply","外面的世界真好玩兒，爹爹為何老是說外面很恐怖呢？\n");
  setup();
  set_living_name("outboy");
  call_out("go_way",60);
}

int go_way()
{
  object ob = this_object();
  if(ob->is_busy())
  {
    remove_call_out("go_way");
    call_out("go_way",10);
    return 1;
  }

  ob->set("go_home",0);
  command("say 嗯，這裡看的差不多了，該去別處了。");
  random_move();
  switch(random(4))
  {
    case 0 : command("say 去天城西門看看麻雀好囉...");             ob->move("/open/world1/acme/area/farm1");
             command("say 嗨..小麻雀們...");
             break;
    case 1 : command("say 聽說後山有個山洞，我去看看好囉...");
             ob->move(__DIR__"../holl-n");
             command("say 哇..好奇特的草呀！");
             break;
    case 2 : command("say 步靈城的無名墓好像很好玩，我去逛逛好囉...");
             ob->move("/open/world1/cominging/area/herohouse");
             command("say 真壯觀的地方！不知是誰的墓呀？");
             break;
    case 3 : command("say 獵戶那的鴨子不知生蛋了沒，去看一下好了...");
             ob->move("/open/world1/acme/area/backyard");
             command("say 大嬸...這邊的鴨子真大隻呀..");
             break;
  }
  call_out("go_way",120);
  return 1;
}

int accept_object(object who, object ob)
{

  object npc=this_object();
  if(npc->is_busy() || npc->is_fight())
    return notify_fail("小悠似乎正在忙。\n");
 if(ob->query("id") == "re letter" && who->query_temp("get_mission"))
  {
    if(npc->query("go_home"))
    {
      command("flop");
      command("say 我已經回家囉，你給我這做什麼呢？");
      return notify_fail("");
    }
    destruct(ob);
    command("say 這... 這是父親的手書嗎");
    command("say 好吧，都被你找到我囉，我就回家一趟");
    message_vision(HIW"\n[$N返回家去了]\n\n"NOR,npc);
    remove_call_out("go_way");
    npc->move(__DIR__"../yu_home");
    who->delete_temp("get_mission");
    who->set_temp("pass_mission",1);
    npc->set("go_home",1);
    return 1;
  }
  else
  {
   if( ob->query("id") != "re letter")
     {
       command("say 謝謝了，可以拿去買糖囉。");
       command("jump");
       destruct(ob);
     }   
   else
     {
       command("say 你看起來好邪惡，我不相信你。");
       random_move();
       return notify_fail("");
     }  
  }
}















