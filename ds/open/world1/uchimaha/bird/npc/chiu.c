#include <ansi.h>
inherit NPC;
void create()
{
 set_name("秋錦",({"chiu gin","chiu","gin"}));
 set("long","她是在獵狐村中可以跟王轑媲美的天才織布少女。\n");
 set("age",17);
 set("gender","女性");
 set("level",7);
 set("title","織布少女");
 set_skill("parry",10);
 set_skill("dodge",10);
 set("chat_chance",10);
 set("chat_msg", ({"秋錦哭著說道:都沒有人相信我....\n",
                   (:command("cry"):),
                   (:command("sob"):),
 }));
 set("chat_chance_combat",200);
 set("talk_reply","你能幫我一點忙(help)嗎?\n");
 set("inquiry/help","其實要做防具, 蛇皮比狐皮更好, 但是在村中的人都不相
信我....你能幫我拿張好蛇皮來嗎? 我要證明給他們看!\n");
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "snake fur")
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
             obj->start_busy(10);
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
            say(HIY"秋錦瞧了樵這張蛇皮。\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 2:
            command("say 這張蛇皮是上上之選, 可以織出很好的東西來。");
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
            command("say 我用一部份的蛇皮做出了一些護具, 就算是給你的答謝禮吧。");
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 6:
            fur=new(__DIR__"obj/hands");
            fur->move(obj);
            command("give hands to "+ me->query("id") );
            obj->delete_temp("givefur");
            break;
          }
}

