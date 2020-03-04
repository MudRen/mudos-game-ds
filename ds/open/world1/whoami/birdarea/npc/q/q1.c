#include <ansi.h>
inherit NPC;
void create()
{
        set_name("探險家",({ "explorer" })); 
        set("gender", "男性" );
        set("long","一個從外地來此的探險家，似乎可以從他身上問出不少的情報•\n");
        set("level", 10);
        set("age",38+random(8));
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("no_fight",1); 
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
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
  if(strsrch(str,"情報") != -1)
  {
    command("think");
    if ( (this_player()->query("level")) >= 45 && (ob->query_temp("pe")) <= 1){
    command("sigh");
    command("say 這位大俠..小弟有一事相求..");
    message_vision
(YEL"探險家說﹕據說傳說中的魔物"HIW"九"HIY"尾"NOR+YEL"正好出現在這"HIW"東北"NOR+YEL"澤林之中..\n"NOR,me);
    message_vision
(YEL"探險家說﹕還盼望這位大俠能將"HIW"九"HIY"尾"NOR+YEL"擊敗，並且將它的皮撕下給我！\n"NOR,me);
    } else {    
    command("dunno");
    command("say 我沒什麼情報可以給你..別來找我了..");
    }
  } 
  if(strsrch(str,"九尾") != -1)
  { 
    command("hmm"); 
    switch(random(10)){
    case 0..3:
    command("say 它可是一種很恐怖的怪物..");  
    command("say 它多年前曾經出現在這世上，那時可真的是人類的浩劫..");   
    command("say 後來它被一個英雄用封印術，封印了起來..");  
    break;
    case 4..6:
    command("say 它可是一種很恐怖的怪物..");  
    command("say 它懂得許\多種妖術..但它最善長的還是變身術..");  
    break;
    default:    command("say 它應該就在附近的洞裡啊？");   
    command("say 難到是我的情報有錯嗎？");  
    command("think");  
    break;    }
  } 
  if(strsrch(str,"皮") != -1)
  { 
    command("hmm"); 
    command("say 沒錯..我就是要它的皮.."); 
    command("say 至於我要拿來做什麼..這你就不必知道了.."); 
  } 
  if(strsrch(str,"英雄") != -1)
  { 
    command("think"); 
    command("say 那個英雄用盡了全身的力量，換來了世界的和平.."); 
    command("say 最後也死了..真是了不起的傢伙.."); 
  }  
  if(strsrch(str,"封印") != -1)
  { 
    command("say 沒錯..九尾當時的確被封印住了"); 
    command("say 至於他為什麼會再次的活了過來，我就不清楚了"); 
  }  
  if(strsrch(str,"變身術") != -1)
  { 
    command("say 九尾常常利用人性的弱點變身成為美女..把人騙進洞內..吸收他的力量..");  
    command("say 要是你看到美女出現在不該出現的地方..別懷疑..他就是九尾妖狐！！");  
    this_player()->set_temp("can_k",1);
  }
  if(strsrch(str,"洞") != -1)
  { 
    command("say 洞..？"); 
    command("say 沒錯啊..九尾應該就在這附近的洞裡啊..?"); 
    this_player()->set_temp("can_enter",1);
  }  
return;
}
int accept_object(object who, object ob)
{
        object tob, gift;
        tob = this_object();
        if( ob->query("id")!="fox fur" || query_temp("pe") ){
        command("say 我已經有了喔，不過你要給我，我還是收下吧•");
        command("smile");
        }else{
        set_temp("pe",1);
        command("say 真是太感謝你了，"+RANK_D->query_respect(who)+"！\n");
        command("say 這個東西給你，就當作是報酬吧！");
        gift=new(__DIR__"scroll");
        message_vision("$N拿出一個"+ gift->query("name") +"給$n\n", tob, who);
        gift->move(who);
        call_out("delay",600,this_object());
        set("long","一個從外地來的探險家，正摸著他手上狐皮。\n");
        }       
        return 1;
}

void delay(object tob)
{
delete_temp("pe");
        set("long","一個從外地來的探險家，似乎可以從他身上問出不少的情報•\n");
        return;
}


