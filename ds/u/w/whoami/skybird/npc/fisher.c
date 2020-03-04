#include <ansi.h>
inherit NPC;
void create()
{
 set_name("漁商",({"fisher"}));
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
set("talk_reply","最近都抓不到魚....看來咱們要去喝西北風了, 這樣吧, 只要兄弟可以抓到魚, 我以市價的一半購買...如何?\n"NOR);
 set("chat_msg", ({"漁商嘆了一口長氣....\n",
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
        object obj,me;
      me=this_player();
        obj=this_object();
        if(ob->name()=="魚肉")
        {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請閣下稍待一下...");
             return 1;
          }
	message_vision("$N給了漁商一個"+ob->query("name")+"。\n",who);
	
             obj->start_busy(1);
             destruct(ob);
         command("smile");
            add_money("coin",70);
            command("give 70 coin to "+me->query("id"));
             return 1;
       }

        if(ob->name() =="鯉魚肉")
        {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請閣下稍待一下...");
             return 1;
          }
	message_vision("$N給了漁商一個"+ob->query("name")+"。\n",who);
             obj->start_busy(1);
             destruct(ob);
         command("smile");
            add_money("coin",200);
            command("give 200 coin to "+me->query("id"));
             return 1;
        }
        if(ob->name()=="鰻魚肉")
        {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請閣下稍待一下...");
             return 1;
          }
	message_vision("$N給了漁商一個"+ob->query("name")+"。\n",who);
             obj->start_busy(1);
             destruct(ob);
         command("smile");
            add_money("coin",160);
            command("give 160 coin to "+me->query("id"));
             return 1;
        }
        if(ob->name()=="鮪魚肉")
        {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請閣下稍待一下...");
             return 1;
          }
	message_vision("$N給了漁商一個"+ob->query("name")+"。\n",who);
             obj->start_busy(1);
             destruct(ob);
         command("smile");
            add_money("coin",150);
            command("give 150 coin to "+me->query("id"));
             return 1;
        }
}


