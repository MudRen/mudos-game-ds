#include <ansi.h>
inherit NPC;
void create()
{
 set_name("漁客",({"fisher"}));
 set("long",@LONG
一個常在漁市場客串賣出的漁商, 看起來一副愁眉苦臉的
樣子, 似乎有很多的煩腦...
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","男性");
 set("level",9);
 set_skill("hammer", 20);
 set("chat_chance",10);
 set("chat_msg", ({"漁商嘆了一口長氣....\n",
		   "漁商愁苦的說著: 糟了糟了....近來"+HIY+"漁獲"+NOR+"真是....\n",
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="魚肉")
        {
           command("? "+who->query("id"));
           command("say 你給小民這東西有用嗎...?");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請閣下稍待一下...");
             return 0;
          }
	message_vision("$N給了漁客一個"+ob->query("name")+"。\n",who);
             obj->start_busy(10);
             obj->set_temp("find_fish",1);
             destruct(ob);
             call_out("find_fish",1,obj);
             return 1;
        }

}

void find_fish()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("find_fish");
      switch( i ) {
          case 1:
            command("say 啊! 這魚肉是給小民的嗎...?");
            command("look "+ob->query("name")+" ");
            obj->set_temp("find_fish",i+1);
            call_out("find_fish",3,me);
            break;
          case 2:
            message_vision(YEL"$N將抓得活魚, 取得魚肉的過程告訴漁客。\n"NOR,me);
            obj->set_temp("find_fish",i+1);
            call_out("find_fish",3,me);
            break;
          case 3:
	    command("soga");
            command("say 原來如此...。");
            command("hoho");
	    obj->delete_temp("find_fish");
            break;
          case 4:
	    
            }
}