#include <ansi.h>
inherit NPC;
void looking_for_help();
void create()
{
        set_name("小女孩" , ({ "litte girl" , "girl"}) );
        set("level",1); 
        set("race","human");
        set("gender","女性");
        set("age",5+random(5));
        set("no_fight",1); 
        set("max_hp",10000);      
        set("long","在你眼前的是一個年輕的小女孩，看來她是在這裡迷了路了，看\n" 
                   "她慌亂的樣子，你不經想要幫幫她•\n");
        set("chat_msg", ({
           (: command("help!") :),
           (: command("cry") :),
        })); 
        set("chat_chance_combat",3000);
        set("chat_msg_combat",({
           (: looking_for_help :),
        }));  
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
        setup();
}

void init()
{ 
  object ob1; 

  object ob=this_object(); 
  object me=this_player();      
  object inv=environment(ob);
  if(inv->query("short") == HIY"狐穴"BLK"－"NOR"深處")
  {
    call_out("stupid",1,ob); 
    set_temp("stupid",1);  }
 
  if ( me->query_temp("can_k")){
  set("long","在你眼前的是一個年輕的小女孩，看來她是在這裡迷了路了•不\n" 
             "過她身上似乎毫髮未傷，而且你也能感受到從她身上所散發出的\n"
             "淡淡妖氣，難不成她就是九尾的化身•\n");  
  set("no_fight",0);
  }
  add_action("do_no_ask","ask"); 
}
int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}
void stupid()
{
      int i;
      object me,obj,ob1;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("stupid");
      switch( i ) {
          case 1:
            command("hehe"); 
            command("grin");
            obj->set_temp("stupid",i+1);
            call_out("stupid",1,me);
            break;
          case 2:
            set_name( HIW"九"HIY"尾"NOR, ({ "killer fox" , "fox"}) );     
            set("title",HIR"殺人狐");
            command("say 又騙到一個呆瓜了..看來今天真是收穫不少啊！");
            obj->set_temp("stupid",i+1); 
            call_out("stupid",1,me);
            break;
          case 3:
            message_vision(HIB"正當$N張開大口要把$n吃下去的同時•••\n"NOR,obj,me);
            obj->set_temp("stupid",i+1);
            call_out("stupid",1,me);
            break;
          case 4: 
            message_vision(HIW"$N不顧一切的用最快的速度逃開這裡！！\n"NOR,me); 
            tell_object(me,HIR"你在逃命的過程還是受了不小的傷\n");
            tell_object(me,HIY"你下定決心一定還要再去殺了那隻妖狐");
            me->set_temp("can_k",1);
            me->set_temp("can_enter",1);
            me->set("hp",10);
            me->move("/open/world1/whoami/birdarea/village1"); 
            "/open/world1/whoami/birdarea/fox18.c"->delete("exits/enter");
            ob1=new(__DIR__"qgirl");
            ob1->move("/open/world1/whoami/birdarea/fox18");
            destruct(obj);
            obj->delete_temp("stupid");
            break;
          }
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"迷路") != -1)
  {
    command("cry " + this_player()->query("id"));
    command("say 對呀..我迷路了..你可以帶我回家嗎？");  
    command("@@");
  }
  if(strsrch(str,"可") != -1)
  {
    command("flip " + this_player()->query("id"));
    command("follow " + this_player()->query("id"));
    command("say 那我們走吧！我家就在前面不遠處！"); 
 "/open/world1/whoami/birdarea/fox18.c"->add("exits", 
([ "enter" : "/open/world1/whoami/birdarea/fox20.c"]));
  }
  return;
}

void looking_for_help()
{ 
    object me=this_object();
    object inv=environment(me);
    message_vision("$N"HIW"曉得事蹟敗露，一溜煙就不見了！\n"NOR,me,this_player());
    new(__DIR__"spider")->move(inv);
    new(__DIR__"qgirl1")->move("/open/world1/whoami/birdarea/fox19");
message_vision("突然間一隻"HIR"噬血"MAG"蜘蛛"NOR"出現在你的眼前，擋住你的去路！\n"NOR,
this_player()); 
    destruct(me);
    return;
}

