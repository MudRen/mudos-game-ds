#include <ansi.h>
inherit NPC;
void create()
{
 set_name("紫俠",({"purpler"})); 
 set("long","她是在江湖上傳聞的飛天女賊，年紀輕輕卻身手非凡，常常劫富\n"
            "濟貧，是貧民的大恩人，但富豪卻都恨她牙癢癢的，想致她於死\n"
            "地，但現在她卻受了重傷...\n");
 set("age",20);
 set("gender","女性");
 set("level",20);
 set("title",HIW+BLK"飛天女賊"NOR);
 set_skill("parry",50);
 set_skill("dodge",100);
 set("chat_chance",20);
 set("max_hp",10000);
 set("hp",1);
 set("chat_msg", ({ 

YEL"紫俠低聲說道：要是能拿到那"HIW"靈丹"NOR+YEL"的話....可是....沒時間了....怎麼辦....\n"NOR,
YEL"紫俠低聲說道：早知道就不去偷那不值錢的東西了...不然就不會中計受傷了....\n"NOR,
YEL"紫俠的胸口滲出了血水\n"NOR,
                   (:command("sigh"):),
                   (:command("walileh"):),
 }));
 set("talk_reply","快救救我啊！我需要生生造化丹來救我的命！\n");
 setup();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "stream pill")
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
             message_vision("$N給了紫俠一粒"+ob->query("name")+"。\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givestone",1);
             destruct(ob);
             call_out("givestone",1,who);
return 1;
        }
}
void givestone()
{
      int i;
      object me,obj,stone;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givestone");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"紫俠瞧了瞧這粒丹藥。\n"NOR);
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 2:
            say(HIY"紫俠用顫抖的手拿起生生造化丹並吃下。\n"NOR);
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 3:
            command("say 謝謝....救了我的性命....");
            command("bow");
            obj->set_temp("givestone",i+1);
            call_out("givestone",2,me);
            break;
          case 4:
            command("say 我這有一個偷來的奇特石頭, 不嫌棄的話就拿去吧");
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 5:
            command("say 傳聞好像刑獨風老前輩在找這個石頭, 不如你去找他看看吧");
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 6:
            stone=new(__DIR__"obj/stone");
            stone->move(obj);
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givestone");
            message_vision("她說完話後就像陣煙似的離開了。\n",me);
            destruct(obj);
            break;
         }
}

