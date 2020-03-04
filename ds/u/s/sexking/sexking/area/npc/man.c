#include <ansi.h>
inherit NPC;
void create()
{
        set_name("相撲力士",({ "man","man" }));
        set("long",
        "他是一位日本相撲力士，身材十分龐大，好像隨時可以壓死你。\n"
        );
        set("age",50);
        set("level",20);
        set("gender", "男性");
        set("str",50);                  
        set("dex",20);                  
        set("con",50);                
        set("int",20); 
        set("exp",5421);                
        set("attitude", "peaceful");
        set("combat_exp",2000);         
        set_skill("unarmed",60);   
        set_skill("parry",60);          
        set_skill("dodge",10);  
        set_skill("perception",10);
        set_skill("combat",50);        
        set("talk_reply","來做相撲吧...吃胖一點...嘻嘻嘻。");
        set("chat_chance",8);
        set("chat_msg", ({
  name()+"說道：人生就是吃吃吃。\n",
  name()+"說道:小子!你要給我好吃的東西嗎? 。\n",
(: command("hoho") :),
(: command(":)") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        "相撲力士把身體湊過來想壓住你。\n",
         (: command("angry") :),
    }) );
        setup();
       carry_object(__DIR__"item/boil");
       }
void die()
{
        message_vision("$N臨死前大聲的說:我還沒吃到天下美食啊∼\n",this_object());
        ::die();
}
int accept_object(object who, object ob)
{
        object sex,a,ll,me;
        sex = this_object();
        me = this_player();
        ll =new(__DIR__"lobser");
        if( ob->query("id")!="lobser" || query_temp("lobser") ) return 0;
        message_vision(HIG"相撲力士吃驚的說:哇！這難道就是傳說中最好吃的"HIR"龍蝦"NOR"?\n"NOR,me);
        command("say 謝謝啦!");
        me->start_busy(2);
        set_temp("lobser",1);
        call_out("wa",3,me);
        call_out("wa2",5,me);
        call_out("ya",7,me);
        call_out("delay",600,this_object());
        set("chat_chance", 10);
        set("chat_msg", ({
  name()+"高興的說道：龍蝦真好吃。\n",
  name()+"不段的回味著吃龍蝦的快感! 。\n",
(: command("hoho") :),
(: command(":)") :),
}) );
return 1;
}
void wa(object me)
{
     if(!me) return;
     message_vision(HIG"相撲力士突然從背後拿出了一支火把。\n"NOR,me);
     return;
}
void wa2(object me)
{
     if(!me) return;
     message_vision(HIY"相撲力士抓起"HIR"龍蝦"NOR"烤了一烤..一口氣咽了下去。\n"NOR,me);
     return;
}
void ya(object me)
{
     if(!me) return;
     message_vision(HIY"相撲力士高興的說:好吃!好吃!真好吃!謝謝你啦!。\n"NOR,me);
     this_player()->add("popularity", 2);
     set_temp("lobser",1);
     tell_object(this_player(),HIM"由於你幫了相撲力士一個大忙所以得到了 2點聲望。\n"NOR);

     return;
}
void delay(object sex)
{
delete_temp("lobser");
set("chat_chance",8);
 set("chat_msg", ({
  name()+"說道：人生就是吃吃吃。\n",
  name()+"說道:小子!你要給我好吃的東西嗎? 。\n",
(: command("hoho") :),
(: command(":)") :),
}) );
        return;
}

        


