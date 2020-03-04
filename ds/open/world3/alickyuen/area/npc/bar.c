//updated
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(RED"酒保"NOR, ({"bartender"}) );       
	set("long", "一個酒保,負責看守這間酒吧的,面上露出不安的神態。\n");
	set("race", "人類");
	set("age", 40);
	set("level", 5);
        set("chat_chance",6);
        set("chat_msg",({
        (:command("sigh"):),            
        }) );
                set("talk_reply","你能幫我一點小忙(help)嗎？\n");
                set("inquiry/help","這幾天的紅酒都賣光了,好慘耶。\n");
	setup();

}
int accept_object(object who,object ob)
{
        object bottle;

        if(ob->name()!="紅酒")  return 0;
        else {
                
          if(this_object()->query_temp("give_bottle")) 
          {
            command("say 我已有足夠的紅酒了...多謝....");
            command("? "+who->query("id"));
            command("say 你還是自己留著喝吧...");
            return 0;
          }    
        message_vision("$N給了酒保一樽$n。",who,ob);
        destruct(ob);
        command("say 多謝你送我紅酒喔...不然我今天賺少很多錢...");
        command("thank "+who->query("id"));
        command("hmm");
        command("say 我前個日檢到個寶石就送給你吧。");
        bottle=new(__DIR__"obj/crystal");
        bottle->move(who);
        set("chat_msg",({
        "酒保說道：還好，有紅酒賣了..\n",
        (:command("grin"):),            
        }) );
        set_temp("give_bottle",1);
        call_out("delay",1200,this_object());
        return 1;
        }

}
void delay(object bartender)
{
        if(!bartender) return;
        bartender->set_temp("give_bottle",0);
        bartender->set("chat_msg",({
        (:command("sigh"):),            
        }) );
        return;
}
