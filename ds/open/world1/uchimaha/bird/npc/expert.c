#include <ansi.h>
inherit NPC;
void create()
{
 set_name("礦石專家",({"stone expert","expert"}));
 set("long","他是一位專門研究礦石的人。\n");
 set("age",33);
 set("gender","男性");
 set("level",20);
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("chat_msg", ({"礦石專家正在努力的挖礦石，發出ㄎㄡ~~~ㄎㄡ~~~ㄎㄡ~~~的聲響。\n",
                   
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({                         
                         (:command,"say 你太小看我了!!":),
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
           command("say 我是〝礦石〞專家ㄝ....");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了礦石專家一個 "+ob->query("name")+"。\n",who);
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
      object me,obj,plate;
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
            command("say 這是一塊上好的精鐵石，可以打造不錯的武器，我把他還給你吧。");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/iron");
            plate->move(obj);
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givehat");
            break;
          }
}

