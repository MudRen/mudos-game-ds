#include <ansi.h>
inherit NPC;
void create()
{
 set_name("步六弧",({"bu liu hu","bu","hu"}));
 set("long","他是在這村子裡最好的織皮人。\n");
 set("age",43);
 set("gender","男性");
 set("level",20);
 set("title","織皮高手");
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",20);
 set("chat_msg", ({"王轑拿起手中的狐皮面罩嘆了一口氣.\n",
                   (:command("sigh"):),
 }));
set("chat_chance_combat",200);
 set("talk_reply","你能幫老夫一點忙(help)嗎?\n");
 set("inquiry/help","你若能找到傳說中的狐皮, 我便織一張面罩給你.\n");
 set("chat_msg_combat",({                         
                         (:command,"say 你太小看我了!!":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "fox fur")
        {
           command("slap "+who->query("id"));
           command("say 你給我這個是啥啊....-.-");
           return 0;
	}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了王轑一張 "+ob->query("name")+"。\n",who);
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
            say(HIY"王轑摸了摸這張狐皮。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say 就...就是這張皮...太好了....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"王轑拿起狐皮在桌子上縫起來了。\n"NOR);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"過了一會王轑手上便多了一張面罩。\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            command("say 老夫把那張狐皮的一部分做了一張面罩, 便送給你當酬勞吧");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/hat");
            plate->move(obj);
            command("give mask to "+ me->query("id") );
            say(HIY"王轑給了一張面罩。\n"NOR);
            obj->delete_temp("givehat");
            break;
          }
}

