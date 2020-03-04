#include <ansi.h>
inherit NPC;

void create()
{
	set_name("管理員", ({"manager"}) );
	set("long", "一個管理員，負責管理車站內的工作。\n");
	set("race", "人類");
	set("age", 40);
	set("level", 15);
        set("chat_chance",4);
        set("chat_msg",({
        (:command("sigh"):),            
        }) );
	setup();
}
void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
add_action("do_nod","nod");
}
int do_nod(string arg)
{
      object me;
      me=this_player();
          if(!me->query_temp("gived_key")) return 0;
 {
        command("say 你能幫我找個小孩嗎？他已失蹤了數天了，希望他沒死去......");
}
}
int accept_object(object who,object ob)
{
        object key;
        if(ob->name()!="鑰匙")  return 0;
        else {
                
          if(this_object()->query_temp("give_key")) 
          {
            command("say 我已找到了鑰匙了......");
     //       command("? "+who->query("id"));
            return 0;
          }    
        message_vision("$N給了管理員一把$n。\n",who,ob);
        destruct(ob);
        command("thank "+who->query("id"));
message_vision("管理員傳送了１００個單位的電子幣去$N的戶口中。\n",me);
who->receive_money(100);
        command("hmm");
        command("say 多謝你幫我找回這條鑰匙，請問你能幫多我一個忙嗎？");
        set_temp("give_key",1);
who->set_temp("gived_key",1);
        call_out("delay",1200,this_object());
        return 1;
        }

}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("go_child")) return 0;
 {
command("say 找到了他嗎？");
tell_object(me,"你把小孩的身處地點一五一十的說給管理員聽。\n");
tell_object(me,"你突然發現自己的頭腦和經驗增進了。\n");
me->add("exp",1000);
me->delete_temp("go_child");
}
}
void delay(object manager)
{
        if(!manager) return;
        manager->set_temp("give_key",0);
        return;
}