#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG"小魚"NOR,({"small fish","fish"}) );
        set("long",
 "一眼就看的出來哪裡不一樣，它可是這裡的報魚仔喔！[give xxx to fish]\n"
);
        set("age",15);
        set("race","野獸");
        set("level",15);
        set("attitude", "peaceful");
        set("gender", "男性" ); 
        set("limbs", ({ "頭部", "身體", "腹部","背部","腰部" }) ); 
        set("verbs", ({ "bite"}) ); 
        set("chat_chance",6);
        set("chat_msg",({
        "小魚唱道：魚兒魚兒水中遊....A_A..\n",
        (:command("sing"):),            
        }) );

        set_skill("unarmed",30);
        set_skill("dodge",22);
        setup(); 
        carry_object(__DIR__"obj/ticket");
}
int accept_object(object who,object ob)
{
        object x;
        if(ob->name() !="牛皮紙")  return 0; 
        else {
                
          if(this_object()->query_temp("call_boss")) 
          {
            command("say 老大剛出來耶....你要找它???"); 
            command("eh "+who->query("id"));
            return 0;
          }
        message_vision("$N給了小魚一張$n。\n",who,ob);
        destruct(ob);
        command("say 你找到啦！！嗯嗯嗯...好吧！\n"); 
        command("nod "+who->query("id"));
        command("say 那我就叫老大出來吧。"); 
        message("world:world1:vision",HIG"\n\t小魚高喊：『恭迎魚老大∼∼∼∼∼∼』\n"NOR,users());
        x=new(__DIR__"fish-boss");
        x->move(environment(this_object()));
        set("chat_msg",({
        "小魚：恭迎老大！..\n",
        (:command("kneel boss"):),            
        }) ); 
        set_temp("call_boss",1); 
        call_out("reborn",600);
        return 1;
        }

}

