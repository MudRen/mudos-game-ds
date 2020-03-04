#include <ansi.h>
inherit NPC;
void create()
{
        set_name("日本小孩",({ "japen child","child","japen" }));
        set("long",
                "他是一個日本小孩，非常想成為一位強者，正努力的練刀法。\n"
                "。\n"
        );
        set("age",7);
        set("level",8);
        set("gender", "男性");
        set("exp",864);     
        
        set("combat_exp",500);         
        set("evil",-20);  
               
 set_skill("blade",25);          
        set_skill("parry",10);          
        set_skill("dodge",30);  
        set_skill("perception",5);
        set_skill("combat",25);     


        set("chat_chance",30);
        set("chat_msg", ({
  
  name()+"說:我要努力練功\，成為像彥空先生一樣強的人。\n",
  name()+"拿起手上的木刀，對著草人砍去。 \n",
  name()+"不停的揮動手中的木刀，十分努力。\n",
(: command("sweat") :),
(: command("ya") :),
(: command("jump") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "日本小孩大叫：救命啊！爸爸來救我！\n",
         (: command("sob") :),
         (: command("help!") :),
           }) );
        setup();
        carry_object(__DIR__"wp/toy_blade")->wield();
        } 
void die()
{
        message_vision("$N臨死之前哭哭啼啼的說:我還不想死呀.....\n",this_object());
        ::die();
}
