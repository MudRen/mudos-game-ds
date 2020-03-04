#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老乞丐",({ "old beggar","beggar" }) );
        set("long","一個年老、衣服破爛的乞丐, 正在乞討著。\n");
        set("race","人類");
        set("age",70);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "老乞丐十分可憐的唉嘆著..\n",
        }) );
        setup();                
}

int accept_object(object who,object ob)
{
        object jude;

        if(ob->name()!="金絲袋")  return 0;
        else {
                
          if(this_object()->query_temp("give-jude")) 
          {
            command("say 多謝！但剛剛已經有人幫我找回東西了...");
            command("thank "+who->query("id"));
            return 0;
          }
          
      message_vision("$N給了老乞丐一塊$n。\n",who,ob);
        destruct(ob);
        command("say 這是我家傳的寶貝阿！！..終於找到了...");
        command("kneel "+who->query("id"));
        command("say 真的非常感謝..為了回報此恩情，我身上有一塊玉，不如就送給恩公吧。");
        jude=new("/u/c/coffee/area/north_area/item/jude");
        jude->move(who);
        set("chat_msg",({
        "老乞丐：幸好我的傳家之寶終於找到了..不然不知道怎麼對祖先交代...\n",
        (:command("sweat"):),            
        }) );
        set_temp("give-jude",1);
//      call_out("delay",600,this_object());
        return 1;
        }

}

int talk_action(object me)      //talk 時會執行此函式.
{
 if(this_object()->query_temp("give-jude")) command("say 我掉的東西已經找到了，謝謝。");
 else
 {
        switch(random(2))
        {
                case 0: command("say 唉..那口袋子到底跑去哪了...");
                        break;
                case 1: command("say 請問有誰有看到一塊玉嗎？");
                default:
                        break;
        }
 }
 return 1;
}


void reset() 
{
//      if(!beggar) return;
        delete_temp("give-jude");
        set("chat_msg",({
        "老乞丐嘆道：唉..那東西到底跑到哪裡去了.....\n",
        }) );
        return;
}

