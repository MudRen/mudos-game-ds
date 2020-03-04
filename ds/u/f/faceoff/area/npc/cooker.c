#include <ansi.h>
inherit NPC;

void create()
{
        set_name("天梟大廚",({"cook"}) );

set("long",
"你看了一看眼前的廚師, 只見他手中煎鏟翻動, 身前的大鍋\n"
"劈哩啪啦的響著, 你不禁對眼前的這位廚師感到欽佩, 也卓\n"
"實感到廚藝也是一門高深的學問。\n",
);
        set("age",40);
        set("race","人類");
        set("level",12);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance",6);
        set("chat_msg",({
        "天梟大廚自言自語的說: 奇怪了....怎地會不見? \n",
        (:command("sigh"):),            
        "天梟大廚又喃喃自語的說: 那條"HIY"蟲"NOR"到底在哪?\n" ,
        }) );
        set_skill("unarmed",20);
        set_skill("sword",10);
        setup();
}
int accept_object(object who, object ob)
{
        object pill;

        if(ob->name()!="綠腹蟲")  return 0;
        else {
                
          if(this_object()->query_temp("give_pill")) 
          {
            command("say 咦?! 怎地還有一隻小蟲兒??");
            command("? "+who->query("id"));
            command("say ...");
            return 0;
          }

        message_vision("$N給了大廚一隻$n。",who,ob);
        destruct(ob);
        command("say 啊...小蟲兒你可回來啦!!!");
        command("thank "+who->query("id"));
        command("say 謝謝啦! 把我的小蟲兒帶回來了! 這顆神丹就送你吧。");
        pill=new(__DIR__"obj/int_pill");
        pill->move(who);
        set("chat_msg",({
        "大廚對小蟲說道：你總算回來啦..\n",
        (:command("jump"):),            
        }) );
        set_temp("give_pill",1);
        call_out("delay",600,this_object());
        return 1;
        }

}

void delay(object kore)
{
        if(!kore) return;
        kore->set_temp("give_pill",0);
        kore->set("chat_msg",({
        "天梟大廚自言自語的說: 奇怪了....怎地會不見? \n",
        (:command("sigh"):),            
        "天梟大廚又喃喃自語的說: 那條"HIY"蟲"NOR"到底在哪?\n"
        }) );
        return;
}
