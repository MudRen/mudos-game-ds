#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"崎顏神"NOR,({ "ki yin shun","ki","shun" }));
        set("long",
                "他是一位年紀輕輕就刀法高明的扶桑浪人，與天京井和武藏野\n"
                "結拜為兄弟，合稱為「依賀三傑」。\n"
        );
        set("nickname",HIG"依賀三傑之一"NOR);
        set("age",27);
        set("level",35);
        set("gender", "男性");
        set("str",70);                  
        set("dex",90);                  
        set("con",120);                
        set("int",80);                  
        set("exp",27893);        
        
        set("combat_exp",6000);         
        set("evil",-10);  
               
 set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",40);
        set_skill("combat",100);     


        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"將刀靠在肩上在旁邊一直沉默不語。\n",
  name()+"說道: 你們要好好加油。 \n",
 (: command("...") :),
(: command("hmm") :),
(: command("sigh") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "崎顏神使出超酷的架式拔刀應戰。\n",
         (: command("...") :),
           }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
        } 

