// quest mob
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("旅館職員", ({"keeper"}) );
	set("long", "他是這間旅館的職員,可以向他租房休息(book)。\n");
	set("race", "人類");
	set("age", 49);
	set("level", 5);
        set("chat_chance",6);
        set("chat_msg",({
        (:command("sigh"):),           
        (:command("say 應該怎樣辦好呢......"):),   
        }) );
	setup();
}
void init()
{
        add_action("do_book","book");
}
int do_book(string arg) 
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if( arg ="room" )
                return notify_fail("你要訂房嗎？(book room)只要３００個單位的電子幣。\n");
{
                if( !me->can_afford(300) )
                        return notify_fail("你的帳號之中不夠電子幣喔。\n");
                me->receive_money(-300);
                me->add_temp("sleep",1);
                message_vision("$N傳送了３００個單位的電子幣給旅館職員。\n",me,ob);
               // command("nod "+me->query("id"));
command("say 請我跟我來這邊。\n");
me->move("/open/world3/alickyuen/area/inn3"); 
}
        return 1;
}

int accept_object(object who,object ob)
{
        object card;
          if(ob->name()!="磁卡")  return 0;
        else {
                
          if(this_object()->query_temp("give_card")) 
          {
              command("say 給我幹啥，這不是我的。");
            return 0;
          }    
        message_vision("$N給了旅館職員一張$n。\n",who,ob);
        destruct(ob);
        command("flip"+who->query("id"));
          command("say 還好找回這張磁卡，不然給我就.....");
        command("thank "+who->query("id"));
        command("whisper "+who->query("id")+" 我就免費招待你一次吧，請跟我來。");
        who->move("/open/world3/alickyuen/area/inn3"); 
        set("chat_msg",({
        (:command("hmm"):),            
        }) );
        set_temp("give_card",1);

        return 1;
        }

}
void reset()
{
        if(query_temp("give_card") )
                delete_temp("give_card");
}

