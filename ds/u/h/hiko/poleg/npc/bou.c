#include <ansi.h>
inherit NPC;
void create()
{
 set_name("阿泊",({"bou-a","bou"}));
 set("long","他是泊浪村中新一輩的新血,十分健談..村裡人都蠻愛跟他說話的也就\n"
            "因此村裡大大小小的事他都還算清楚，有問題該可以跟他談談(talk)\n");
 set("age",26);
 set("gender","男性");
 set("level",30);
 set("title",HIG"新手漁夫"NOR);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"阿泊說道: 最近真是..怎麼會發生這種事呢...\n",
                   "阿泊喃喃說著:那『東西』也不知道跑哪去了...\n",
                   (:command("sigh"):),
 }));
        set("chat_chance_combat",20);

 set("chat_msg_combat",({"阿泊大叫道:別殺我!...我什麼都說了..."}));
 set("inquiry/村長","村長是不久前才上任的，最近不知為何有點怪怪的...
     似乎跟以前的『隱者』有關\n"NOR); set("inquiry/漁會頭目","就是我們漁會主事呀!住在村裡廣場北側內...\n"NOR);
 set("inquiry/恩怨","聽說最近『村長』和『漁會頭目』因為某事鬧的很不愉快? 到底是怎麼也沒人知道..\n"NOR);
 set("inquiry/隱者","聽說曾經多年前有個不世高手住在此地，不過現在也不知去向了\n"NOR);
 set("inquiry/海賊","那些可惡的傢伙是在村長上任後不久出現的，也不知道哪來的，
    幸虧有漁會頭目在..\n"NOR);
 set("inquiry/東西","那東西..就是我的水手服呀...上次去海邊玩時被潮水不知沖到哪了..若你能幫
    我找到我就跟你說個秘密..\n"NOR);
 setup();
}

int talk_action(object me)        
{
  object ob;      
  ob = this_player();        
      if(random(2))       { 
        command("say 最近泊浪村因為一些『恩怨』鬧的十分不愉快");
        command("say 而且又發生『海賊』出現的事!真是令人感到頭痛");
        command("say 也不知道有誰能幫忙除掉海賊，真是多事的一年"); 
       }
       return 1;
}

int accept_object(object who,object ob)
{
        object obj,me;
        me=this_player();
        obj=this_object();
if(ob->name()!="水手服")
    {
           command("say 這不是我要的東西，請拿回去吧");
           return 0;
    }
        
  else {  
     if(obj->is_busy() || obj->is_fighting())
            {
             command("whisper "+who->query("id")+" 請你等一下。");
             return 0;
             }
            message_vision("$N給了阿泊一件"+ob->query("name")+"。\n",who);
             command("say 我就跟你說了，如果你在村長面前提起漁會頭目(say)");
             command("say 村長就會變的怪怪的唷");
             me->set_temp("knowhate",1);
             destruct(ob);
             return 1;
              
       }
}






