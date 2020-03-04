#include <ansi.h>
inherit NPC;
void create()
{
 set_name("獨臂老人",({"oldman"})); 
 set("long","他是一位曾經闖蕩江湖的男子，自從他的左手被仇家從肩砍斷後\n"
            "，便一直隱居在這裡，成為一個鐵匠，他的夢想就是打造一把神\n"
            "兵利器，但是他好像缺少了什麼....\n");
 set("age",72);
 set("gender","男性");
 set("level",20); 
 set("no_fight",1); 
 set("title",HIW"獨臂鐵匠"NOR);
 set("chat_chance",10);
 set("chat_msg", ({YEL"獨臂老人拿起手中的鐵箝嘆了一口氣.\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 set("reborn",150);
 setup();
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
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"精鐵石") != -1)
  {  
    command("oh");    command("say 你可以去東北澤林的泥沼區碰碰運氣，那裡有不少的鐵石•"); 
  }   
  if(strsrch(str,"缺少") != -1)
  {  
    command("hmm "+this_player()->query("id"));
    command("say 我現在在打造陰陽劍，但是缺了種石頭，叫陰陽鐵石，只有這種石頭才能打造出陰陽劍。"); 
  }
  if(strsrch(str,"陰陽鐵石") != -1)
  {  
    command("say 陰陽鐵石是由陰陽石與精鐵石用內力融合而成的珍貴寶物•"); 
  }  
  if(strsrch(str,"陰陽劍") != -1)
  {  
    command("hehe");
    command("say 等到你幫我拿到陰陽鐵石時，你就會知道了•"); 
  }  
  if(strsrch(str,"陰陽石") != -1)
  {  
    command("hmm "+this_player()->query("id"));
    command("say 陰陽石又是由陰石和陽石組合而成的寶物•");  
    command("say 至於..下落..我就不清楚了..");  }  

return;
}int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "sun-moon iron stone")
        {
           command("flop "+who->query("id"));
           command("say 你給我這個是啥啊....-.-");
           return 0;
        }
if( query_temp("can_not_give") )
        {
           command("hoho");
           command("say 我心願已了..");
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
             command("think"); 
             obj->set_temp("can_not_give");
             obj->set("long","他是一位曾經闖蕩江湖的男子，自從他的左手被仇家從肩砍斷後\n"
                             "，便一直隱居在這裡，成為一個鐵匠，他的夢想就是打造一把神\n"
                             "兵利器，但是他好像缺少了什麼....\n"); 
             obj-> set("chat_msg", ({
                   (:command("hmm")             :),
                   (:command("say 心願已了了.."):),
                   }));
             obj->start_busy(9);
             obj->set_temp("givehat",1);
             destruct(ob); 
            call_out("delete_temp",900); 
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i,exp,pop;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      pop=1+random(3);
      exp=19000+random(5000);
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"老人摸了摸這塊石頭。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 2:
            command("say 謝謝你阿，小兄弟。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"老人拿起了一把劍，開始打造那把劍。\n"NOR);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"過了一會獨臂老人手上多了一把發著藍光和紅光的劍。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 5:
            command("say 我的夢想已經完成了，這把劍在不在我身邊已經不重要了，我就把它給你吧。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 6:
            plate=new(__DIR__"obj/sword1");
            plate->move(obj);
            command("give sword to "+ me->query("id") );
//            me->add("popularity",pop);
//            me->add("exp",exp);
//            tell_object(me,HIW"(你完成此任務，得到了 "+ exp+" 點經驗值與 "+pop+" 點聲望。)\n"NOR);
            obj->delete_temp("givehat"); 
           break;
          }
} 
int delete_temp()
{
 delete_temp("can_not_give"); 
 set("long","他是一位曾經闖蕩江湖的男子，自從他的左手被仇家從肩砍斷後\n"
            "，便一直隱居在這裡，成為一個鐵匠，他的夢想就是打造一把神\n"
            "兵利器，但是他好像缺少了什麼....\n");
 set("chat_msg", ({YEL"獨臂老人拿起手中的鐵箝嘆了一口氣.\n"NOR,
                   (:command("sigh"):),
 }));
 return 1;
}

