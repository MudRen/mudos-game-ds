#include <ansi.h>
inherit NPC;
void create()
{
 set_name("陳寶",({"chen bow","chen","bow"}));
 set("long","他是獵狐村的村長, 他看起來似乎有些煩惱。\n");
 set("age",60);
 set("gender","男性");
 set("level",20);
 set("title","獵狐村村長");
 set_skill("parry",50);
 set_skill("unarmed",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("chat_msg", ({"陳寶低聲的自言自語:怎麼辦...到底該怎麼辦....\n",
                   (:command("sigh"):),
 }));
 set("chat_chance_combat",10);
 set("talk_reply","你能幫老夫一點忙(help)嗎?\n");
 set("inquiry/help","請你幫我找回天狗皮，那是我的傳家寶，請務必要找回來。\n");
 set("inquiry/天狗皮","有一隻大鳥趁我不注意時，把天狗皮給叼走了，
牠好像是往東北澤林﹝泥沼區﹞的方向飛去。\n");
 set("chat_msg_combat",({                         
                         (:command,"say 你太小看我了!!":),
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "skydog fur")
        {
           command("slap "+who->query("id"));
           command("say 這是蝦米東東ㄚ....-_-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
           if( present("godwind bag", who) )
           {
             command("?");
             return 0;
           }

             message_vision("$N給了陳寶一張 "+ob->query("name")+"。\n",who);
             command("think");
             obj->start_busy(6);
             obj->set_temp("givebag",1);
             destruct(ob);
             call_out("givebag",1,who);
return 1;
        }
}
void givebag()
{
      int i;
      object me,obj,wind;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givebag");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"陳寶仔細瞧了瞧這張皮。\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 2:
            command("say 太好了，就是這張皮。");
            obj->set_temp("givebag",i+1);
            call_out("givebag",2,me);
            break;
          case 3:
            say(HIY"陳寶親了親這張皮並且說:我有個東西要送你，你等等。\n"NOR);
            command("dance");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 4:
            say(HIY"陳寶在身旁的箱子中東翻西找的，不知道他在找什麼東西。\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 5:
            command("say 這是我親自做的袋子，便送給你當作酬勞吧。");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 6:
            wind=new(__DIR__"obj/bag");
            wind->move(obj);
            command("give bag to "+ me->query("id") );
            wind->set("no_give", 1);
            obj->delete_temp("givebag");
            break;
          }
}

