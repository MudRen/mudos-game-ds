#include <path.h>
inherit NPC;
int quest();
inherit SELLMAN;

void create()
{
	set_name("機車老麥", ({"machine dealer","dealer"}) );
	set("long", @LONG
維修廠的管理員，來自星聯總部的船隻護理廠，因為酗酒被被派任到
偏遠的礦村來。最近維修廠發生了一些怪事，你如果想知道這附近發
生的事情，可以試著跟他聊聊(talk with dealer)。
LONG
);
	set("race", "人類");
	set("title","混吃等死");
	set("age", 210);
	set("level", 25);
        set("no_fight",1);
        set("storeroom", __DIR__"shop/shop1.c");
        set("sell_list",([
        __DIR__"obj/pill" : 10,
]) );
        set("chat_chance", 5);        
        set("chat_msg", ({
       (: command("say 好想喝酒啊...。") :),
       (:command("why"):),
       (: command("say 這裡的工作無聊死了...") :),
       (: command("say 要是找不到冷卻器車子就不能發動了！") :),
        }));
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！
                只要是住這村子裡的人你都可以問我。");
	setup(); 

}

void init()
{
        ::init();
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
        add_action("do_no_ask","ask");
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"威廉") !=-1)
    command("say 上個月星聯總部派來的臨時村長，可以找他聊天。");
  if(strsrch(str,"比爾") !=-1)
    command("say 他賣的波爾酒最醇了，最近新賣的燉肉更是叫人贊不絕口!!");
  if(strsrch(str,"冷卻器") !=-1)
    command("say 就是我車子的冷卻器啊，大半夜有隻畜生給我咬走了的樣子。");
  if(strsrch(str,"礦工的孩子") !=-1)
    command("say 他的父親給隻灰色的大畜生咬死了，現在只好流落街頭。");
  if(strsrch(str,"廚師") !=-1)
    command("say 那個怪人老是把自己關在廚房裡，哼，一定有問題！");
  if(strsrch(str,"畜生") !=-1)
    command("say 好大隻！！還咬傷我！！一隻灰色的大畜生，跟豬差不多大！");
  if(strsrch(str,"燉肉") !=-1)
    command("say 剛不是說嗎，這村子最好吃的肉就是比爾新賣的燉肉了!!");
  if(strsrch(str,"波爾酒") !=-1)
    command("say 比爾自己特製的好酒，你也應該喝喝看!!");
  if(strsrch(str,"礦工") !=-1)
    command("say 因為這裡是聯邦管轄的礦區，有很多各地來的工人在這裡工作。");
  return;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int accept_object(object who,object ob)
{
        object pill;

        if(ob->name()!= "汽車冷卻器")  return 0;
        else {
                
          if(this_object()->query_temp("give_pill")) 
          {
            command("say 我的汽車冷卻器已經找回來了.. 怎麼你還有？");
            command("? "+who->query("id"));
            command("say 你拿去賣掉好了∼");
            return 0;
          }
          
        message_vision("$N把$n舉起來在老麥眼前晃了晃∼。\n",who,ob);
        destruct(ob);
        command("say 喔耶∼∼謝謝你啦∼你宰了那畜生啊？？");
        command("thank "+who->query("id"));
        command("say 來∼嘿嘿∼給你好用的！
            (老麥把兩顆東西塞到你手中...。)
            (你覺得自己又多了一些冒險經驗。)");
        this_player()->add("exp",(this_player()->query("level") * 500) + (random((this_player()->query("level")*100))+1000));
        pill=new(__DIR__"obj/pill2");
        pill->move(who);
        pill=new(__DIR__"obj/pill2");
        pill->move(who);
        set("chat_msg",({
        "機車老麥高興的玩弄著冷卻器，又叫又跳的∼。\n",
        (:command("idle"):),            
        }) );
        set_temp("give_pill",1);
        return 1;
        }

}

void reset()
{
//      if(!dealer) return;
        delete_temp("give_pill");
        set("chat_msg",({
        (: command("say 好想喝酒啊...。") :),
       (:command("why"):),
       (: command("say 這裡的工作無聊死了...") :),
       (: command("say 要是找不到冷卻器車子就不能發動了！") :),
        }));
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！
                只要是住這村子裡的人你都可以問我。");
}
