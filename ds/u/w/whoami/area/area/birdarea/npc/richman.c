#include <ansi.h>
inherit NPC;
void create()
{
 set_name("富翁",({"rich man","man"}));
 set("long","他是獵狐村的首富，聽說他是專門幹一些不為人知的地下勾當才\n"

            "會這麼的有錢的•但是他似乎遇到了點小麻煩•\n");
 set("age",60);
 set("gender","男性");
 set("level",20);
 set("title",HIR"獵狐村"NOR"首富");
 set("no_fight",1);
 set("chat_chance",10);
 set("chat_msg", ({ YEL"富翁低聲的自言自語:怎麼辦啊..那麼重要的東西居然..\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
 setup(); 
 add_money("coin",random(50000));
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
  if(strsrch(str,"麻煩") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1){
    command("say 我沒什麼麻煩啊.."); 
    command("hoho");  
    } else {
    command("say 請你幫我找回我收藏已久的石頭吧，那個東西不知道是那天被人給摸走了");
    command("thank "+ this_player()->query("id"));
    }
  }   
  if(strsrch(str,"地下勾當") != -1)
  { 
    command("hehe"); 
    command("say 這種事你是不須要知道的..");  
  }
  if(strsrch(str,"重要的東西") != -1)
  { 
    command("say 就是那顆我收藏已久的石頭啊！"); 
  }        
     
  if(strsrch(str,"石頭") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1){
    command("say 那是我的秘密啊.."); 
    command("say 我可是不會給你看的");
    command("giggle "+ this_player()->query("id")); 
    } else {
    command("say 那顆石頭叫做五彩石，在暗處能發出光芒喔！");
    } 

}  
return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object(); 
if(ob->query("id") != "five color stone")
        {
           command("flop "+who->query("id"));
           command("say 這不是我要的東西啦..");
          return 1;
} 
if( query_temp("can_not_give") ){
           command("hoho");
           command("say 給我這做啥？");
           return 1;
}        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }

             message_vision("$N給了$n一"+ob->query("unit")+ob->query("name")+"。\n",who,obj);
             command("think");
             obj->set_temp("can_not_give",1);
             obj->set_temp("giveitem",1);
             destruct(ob); 
            obj->set("long","他是獵狐村的首富，聽說他是專門幹一些不為人知的地下勾當才\n"
                            "會這麼的有錢的•\n");
        
            obj->set("chat_msg", ({ (:command("say 最後還是找到了.."):),
                                    (:command("sweat"):),
                                  }));
             call_out("giveitem",1,who); 
             call_out("rb",150);
             return 1;
        }
}
void giveitem()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveitem");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"富翁仔細的打量了一下這顆石頭。\n"NOR);
            obj->set_temp("giveitem",i+1);
            call_out("giveitem",3,me);
            break;
          case 2:
            command("say 不錯，就是這顆石頭");
             obj->set_temp("giveitem",i+1);
             call_out("giveitem",1,me);
             break;
          case 3:
            say(HIY"富翁小心翼翼把石頭收了起來•\n"NOR); 
            switch( random(10) ){
             case 0..3:
              command("say 你果然就是那個賊！！");
              message_vision("正當$N想開口解釋的時候•••",me);
              message_vision(HIW"\n突然間$N旁邊跳出兩個壯漢，把$N拖進了牢裡！\n"NOR,me);
              obj->delete_temp("giveitem");
              me->move(__DIR__"../jail");
              break;
             default: 
              command("say 我有個東西要送你，你等等。");
              obj->set_temp("giveitem",i+1);
              call_out("giveitem",2,me);
              break;
              }    
            break;
         case 4: 
            item=new(__DIR__"obj/seal");
            item->move(obj); 
            message_vision(HIY"$N從身上拿出一個"NOR+item->query("name")+HIY"•\n"NOR,obj);
            obj->set_temp("giveitem",i+1);
            call_out("giveitem",1,me);
            break;
          case 5:
            command("say 這是我花大錢買下的，不知道有什麼用，那就送你吧");
            command("give seal to "+ me->query("id") );
            obj->set_temp("giveitem",i+1); 
          }
}

int rb()
{ 
    delete_temp("can_not_give");
    set("long","他是獵狐村的首富，聽說他是專門幹一些不為人知的地下勾當才\n"
               "會這麼的有錢的•但是他似乎遇到了點小麻煩•\n"); 
    set("chat_msg", ({ YEL"富翁低聲的自言自語:怎麼辦啊..那麼重要的東西居然..\n"NOR,
                     (:command("sigh"):),
                     }));
    message_vision(YEL"$N咳了兩聲。\n"NOR,this_object());
    return 1;
}

