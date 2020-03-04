#include <ansi.h>
inherit NPC;
void create()
{
 set_name("秋錦",({"chiu gin","chiu","gin"}));  
 set("long","她是在獵狐村中可以跟王轑媲美的天才織布少女。她一直說狐皮\n"
            "並不是最好的防具，不過好像沒什麼人願意採信她的話就是了..\n");
 set("age",17);
 set("gender","女性");
 set("level",7);
 set("nickname","織布少女");
 set("title",HIR"獵狐村"NOR);
 set("no_fight",1);
 set("chat_chance",10); 
 set("chat_msg", ({
                   YEL"秋錦哭著說道:都沒有人相信我....\n"NOR,
                   (:command("cry"):),
                   (:command("sob"):),
 }));

 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 setup();
}

void init()
{
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
  add_action("do_no_ask","ask");
}

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query_temp("ko_crocodile") >= 1  && !objectp( ob = present("crocodile fur" , me))){
    command("say 如果你能把你身上的那張鱷魚的皮給我，我就織一件裝備給你！");
    command("bow "+ me->query("id") );   
    } else {    command("say 如果你能幫我拿到一張鱷魚的皮，我就織一件裝備給你！");
    command("addoil "+ me->query("id") );   
    }
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
  if(strsrch(str,"狐皮") != -1)
  { 
    command("nod "+this_player()->query("id")); 
    command("say 狐皮做出來的防具絕對不是最好的！");
    command("say 我認為做防具最好還是要拿鱷魚皮來做..");
  }   
  if(strsrch(str,"鱷魚皮") != -1)
  { 
    command("hmm "+this_player()->query("id")); 
    command("say 鱷魚皮當然要從鱷魚身上拿啦！");
    command("say 至於鱷魚要去那找..我就不知道了..");
  }  

return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "crocodile fur")
        {
           command("say 不是這個....");
           return 0;
} 
if( query_temp("no_give") )
        {
           command("say 不是這個....");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了秋錦一張 "+ob->query("name")+"。\n",who);
             command("bow");
             obj->set_temp("no_give",1);
             obj->set_temp("givefur",1);
             destruct(ob);
             call_out("givefur",1,who);
return 1;
        }
}
void givefur()
{
      int i;
      object me,obj,fur;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givefur");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"秋錦瞧了瞧這張鱷魚皮。\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 2:
            command("say 這張鱷魚皮是上上之選, 可以織出很好的東西來。");
            command("smile");
            obj->set_temp("givefur",i+1);
            call_out("givefur",2,me);
            break;
          case 3:
            say(HIY"秋錦走到房裡, 防裡傳出織布機的運轉聲。\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 4:
            say(HIY"過了一會秋錦從房裡走出, 手上拿著一雙護手。\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 5:
            command("say 我用一部份的鱷魚皮做出了一些護具, 就算是給你的答謝禮吧。");
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 6:
            fur=new(__DIR__"obj/hands");
            fur->move(obj);
            command("give hands to "+ me->query("id") );
            obj->delete_temp("givefur");
            obj->delete_temp("no_give");
            break;
             
          }
}

