#include <ansi.h>
inherit NPC;
void create()
{
 set_name("礦石專家",({"stone expert","expert"}));
 set("long","他是一位專門研究礦石的人。\n");
 set("age",33+random(5));
 set("gender","男性");
 set("level",20);
 set("no_fight",1);
 set("chat_chance",10);
 set("talk_reply","如果你有找到礦石的話, 我可以免費幫你分析ㄡ...:D\n");
 set("chat_msg", ({YEL"礦石專家正在努力的挖礦石，發出ㄎㄡ~~~ㄎㄡ~~~ㄎㄡ~~~的聲響。\n"NOR,
                   
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object(); 
if(ob->query("id") != "iron stone")
        {
           command("slap "+who->query("id"));
           command("say 來亂的啊？");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了礦石專家一個"+ob->query("name")+"。\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,ob,ob1,ob2;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"礦石專家敲了敲這個石頭。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 嗯....這應該不是鐵石....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"礦石專家又敲了敲這塊石頭。\n"NOR);
            command("think");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"礦石專家好像發現了什麼，高興異常。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            switch( random(10) ){
             case 0:
              ob1=new(__DIR__"obj/moon-stone");
              ob1->move(obj);
              message_vision(YEL"$N說： 這是一塊上好的"+ob1->query("name")+YEL"，可以打造不錯的武器，我把它還給你吧。\n"NOR,this_object());
              break;
             case 1:
              ob2=new(__DIR__"obj/sun-stone");
              ob2->move(obj);
              message_vision(YEL"$N說： 這是一塊上好的"+ob2->query("name")+YEL"，可以打造不錯的武器，我把它還給你吧。\n"NOR,this_object());
              break;
             default:
              ob=new(__DIR__"obj/iron");
              ob->move(obj); 
              message_vision(YEL"$N說： 這是一塊上好的"+ob->query("name")+YEL"，可以打造不錯的武器，我把它還給你吧。\n"NOR,this_object());
              break;
             }
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givehat");
            break;
          }
}

