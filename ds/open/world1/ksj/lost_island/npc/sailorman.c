#include <ansi.h>
inherit SELLMAN;
inherit NPC;

void create()
{
  set_name( "水手", ({ "sailorman"}));
  set("long", "一個全身破爛蓬頭垢面的西方水手，腰間繫了把彎刀，身邊放了一個\n"
             +"大帆布袋，看樣子應該是飄流到這邊來的，他正在四處兜售物品。\n\n"
             +"  看存貨請用 <list> \n"
             +"  要買東西用 <buy 物品> <buy 數量 物品> \n\n"
     );
  set("level",30+random(3));
  set("title","蓬頭垢面");
  set("gender", "男性");
  set("race", "人類");
  set("age", 42);
  set("combat_exp",30000);       
  set("evil",-30);              
  set_skill("blade",70);         
  set_skill("parry",40);    
  set_skill("dodge",60);   
  set("attitude", "peaceful");  
  set("talk_reply","客人來買點東西吧，都是罕見的物品呀..");
  set("sell_list",([   
      __DIR__"eq/deerskin-gloves"  : 20, 
      __DIR__"eq/deerskin-boots"   : 20, 
      __DIR__"eq/cow-skin-hat"   : 20,  
      __DIR__"eq/feather-surcoat"   : 20,
      __DIR__"eq/sky-bead"   : 5,  
     ]) );
  set("chat_chance", 15 );  
  set("chat_msg", ({     
      "水手自言自語說道：唉∼雖然發現了"HIW"遺世島"NOR"，但是強烈的"HIW"海流"NOR"卻使得\n"
     +"                  整艘船支離破碎，飄散在島外。\n",
      "水手自言自語說道：不知道其它人生死如何？大約都難逃一劫吧。\n",
      "水手激昂地說道：兄弟們∼我一定會回去找你們的．．咕嚕∼咕嚕嚕\n"
     +"                等我吃飽．．一定．．\n",
      "水手拿出一顆"HIC"藍色石頭"NOR"說道：嗯．．有點受損了，不知道還能不能用？\n",
     (:command("sigh"):),
     }) );
  set("inquiry/遺世島","船長遍尋古文獻，歷時三年，在東方海域上發現的小島，\n"
                      +"據說是上古時代大陸漂移使得整座山漂到海中變成小島，島上生存著\n"
                      +"無數難以想像的異獸，由於整個島被山壁包圍，就算有人發現這個島\n"
                      +"也不知道其中竟另有天地，造化之奇果真難以想像。\n"NOR);
  set("inquiry/石舟","這是我在島上生活的大半年，好不容易才找到的交通工具\n"
                    +"，全靠這神奇的石舟，我才能回到大陸島。\n"NOR);
  set("inquiry/海流","那時後本來海面平靜無波，誰知道突然波濤洶湧，海水像\n"
                    +"是有生命似的，要把船摧毀吞食，實在是太可怕了！\n"NOR);
  set("inquiry/藍色石頭","這個是我的寶貝，說什麼也不會賣你的！除非殺了我！\n"NOR);
  setup();
  carry_object(__DIR__"eq/sea-stone");
  carry_object(__DIR__"eq/sailorman-blade")->wield();
}

void init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_buy","buy");

  if(userp(this_player()))
  {
    message_vision(YEL"\n$N細細聲的說道：遺世島上有好多珍奇百獸，但牠們平常都會躲起\n"
                      "來，只會在沒什麼東西經過時才會跑出來。\n\n"NOR, this_object());
  }
}

int accept_object(object who,object ob)
{
  object obj,journal;
  obj=this_object();

  if(ob->query("id") == "captain's hat")
  {
    if(obj->is_busy() || obj->is_fighting())
      {
        command("whisper "+who->query("id")+" 我沒空，別來煩我。\n");
        return 0;
      }
    message_vision("$N拿給水手一頂 "+ob->query("name")+"，並說明在洞窟所發生的事。\n",who);
    command("sigh");
    message_vision("水手說道：原來船長也遇害了。這本日誌是船長一直很重視的，原本\n"
                   "要還給船長，現在我留著也沒用了，就給你當紀念吧。\n",who);
    obj->start_busy(2);
    destruct(ob);
    journal=new_ob(__DIR__"eq/red-journal");
    journal->move(obj);
    command("give journal to "+ this_player()->query("id") );
    return 1;
  }
  return 0;
}
