//說故事的
#include <ansi.h>
inherit NPC;
void yen();
void create()
{
	set_name(HIG"顏輿"NOR,({"yen-eu","yen"}) );
	set("long","一個全身是傷的老人，兩眼好似充滿了悔恨，看來離死不遠了。\n");
	set("age",50);
	set("level",60);
	set("race","人類");
        set("exp", 7000); //雖然等級高，但是只有四分之一的HP，所以限定經驗值。
                          //因為法術仍然可以殺到，故需要設定。
        
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say 玉兒……玉兒…………"):),
		(:command("sigh"):),
		(:command("sob"):),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say 我不能死！我還有沒做完的事，我絕對不能死！！"):),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",100);
	set_skill("sword",100);

	set("talk_reply","我的傷已經沒救了…但是在我死之前有件重要的事…請…幫幫我…咳咳…好嗎﹖");
	setup();

	carry_object(__DIR__"wp/yun-tsang")->wield();
}
void init()
{
        int hpx;
        ::init();
        hpx= this_object()->query("max_hp");
        this_object()->set("hp",hpx*1/4);
        add_action("do_kill","kill");
        add_action("do_backstab","backstab");
        add_action("do_steal","steal");
        add_action("do_nod","nod");
}
int do_nod()  
{
//      object me;
//      me=this_player();
//       if(me->query_temp("quest/story") > 0)     return    notify_fail("看到你如此誠心，顏輿疲憊的臉上露出安慰的笑容。\n");
       
      call_out("yen",1,this_object());
    

}
void yen()
{

 int i;
 object obj;
 i = this_object()->query_temp("del");
 obj = this_object();

 switch(i){

  case 0:
            command ("say 多謝這位...咳咳...這件事說來話長...");

            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 1:
            command ("sigh");
            command ("say 我曾是風雲一時的大盜，與當時摘星門主並稱星影雙煞…");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 2:
            command ("say 十餘年前，我倆屠滅了另外一群強人，得到了一張記載絕世武\功\的\殘\卷…咳﹗咳﹗");
            say ("顏輿說到一半突然臉色變得很痛苦的樣子....\n");

            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 3:
            command ("say 為了這個絕世武\功\，我們花費好幾年來尋找殘卷剩餘的部分…終於得到了一些線索…");
            say ("顏輿說到這裡，突然劇烈的咳了起來，最後咳出了一大口黑血﹗\n");
            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 4:
            command ("say 嘿嘿…看來我也活不久了，看來當初殺了好友的報應今天總算應了…");
            say ("顏輿看著沾滿血跡的雙掌及前襟，露出了一抹苦澀的笑容。\n");       
            obj->set_temp("del",i+1);
            call_out("yen",3 ,obj);
            break;
  case 5:
            command ("say 我們為了這爭吵起來，就這樣…私慾攻心的我一怒之下殺了他…和他的摘星門…");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 6:
            command ("say 我後來雖然後悔，但絕世武\功\實在太誘人了…我就帶著一身的罪惡出來尋找…");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 7:
            command ("say 不知經過多少苦難…咳咳…還被妖魔砍成這樣…終於找到了殘卷剩餘的部分藏匿的地方……");
           say("顏輿一邊說一邊指著身上駭人的傷口。\n");
            command ("say 結果卻發現東西早就被別人拿走了………");
           say("顏輿說完哈哈大笑起來，笑著笑著突然哇一聲，又嘔出一大口鮮血。\n");
            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 8:
            command ("say 嘿嘿…時候快到了……這裡有個東西…麻煩你……將這個交給摘星門的餘孤……");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 9:
            command ("say 叫…風…風無影…他是…摘星門的…大弟子…是玉兒的…咳咳﹗﹗");

            obj->set_temp("del",i+1);
            call_out("yen",7 ,obj);
            break;
  case 10:
            command ("say 如果你遇到…玉兒…告訴她…爹對不起她…對不起她…咳咳");
            this_player()->set_temp("quest/story",7);
            obj=this_object()->carry_object(__DIR__"obj/old_stone");
            if(obj->name()!="古老的石雕")
            {
               say ("顏輿拿出一個石雕，那石雕卻突然化為粉末！！只見顏輿呆呆的望著手上的粉末。\n");
               command ("say 老天連贖罪的機會也不給我…連贖罪的機會也不給我…");
               say ("顏輿說著說著，聲音愈來愈低微…就這樣…帶著悔恨死了…\n");
               ::die();
             }
               else
             {
               command("give stone to " + this_player()->query("id") );
               command("say 拜託你…了…這樣…我總算…了…了…心願…");
               say("顏輿說完，突然一掌往自己的天靈\蓋\擊\落﹗﹗\n");
               ::die();
              }
 
            break;
  }
}
void do_last()
{  
  int dex,dodge;
  object me;
  me=this_player();
  dodge=me->query_skill("dodge");
  dex=me->query_dex(); 
  if((dodge+dex)<random(70))
  {

     message_vision(HIG"
              顏輿將全身的力量集中於劍上，奮力向$P擊去！！
              只見$P閃躲不及，一把長劍竟將$P連人帶甲刺穿！\n"NOR,me);
     me->die();
     say (GRN"顏輿一招使出，便停住不動，竟是死了，片片石屑隨風飛揚在此地。\n"NOR);
     ::die();
   }      
	else{
        message_vision(RED"\n顏輿奮力一擊不中，當場吐血數升，跌倒在地。\n"NOR,me);
 	me->start_busy(7);
        say (HIR"顏輿恨恨的說道：「老夫縱橫一世，竟斃命於此。報應啊！報應啊！但是這東西我絕不會讓它落入賊人手中！！」\n"NOR);
        say (HIR"顏輿站起來大吼一聲！雙手高舉向天，就這樣站著...死了...只見他手中\落\下\許\多石屑，隨著西風吹向天際。\n"NOR);

        ::die();
        }
}
int do_kill(string arg)
{ 
  object obj;
  obj=this_object();
  if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("顏輿咬牙眥裂喊道：「可惡的賊子！我就算死也絕不屈服於你！！！」\n");
  do_last();
}  
int do_backstab(string arg)
{ 
  object obj;
  obj=this_object();
  if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("顏輿咬牙眥裂喊道：「可惡的賊子！我就算死也絕不屈服於你！！！」\n");
  do_last();
}  
int do_steal(string arg)
{ 
  object obj;
  obj=this_object();
  if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("顏輿咬牙眥裂喊道：「可惡的賊子！我就算死也絕不屈服於你！！！」\n");
  do_last();
}  