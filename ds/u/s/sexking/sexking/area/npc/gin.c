#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"天京井"NOR,({ "tain gin gin","gin","tain" }));
        set("long",
                "他是一位年紀輕輕就刀法高明的扶桑浪人，與武藏野和崎顏神\n"
                "結拜為兄弟，合稱為「依賀三傑」。\n"
        );
        set("nickname",HIC"依賀三傑之一"NOR);
        set("age",23);
        set("level",30);
        set("gender", "男性");
        set("str",30);                  
        set("dex",100);                  
        set("con",90);                
        set("int",65);                  
        set("exp",18213); 
        set("attitude", "peaceful");
        set("combat_exp",6000);         
        set("evil",-30);                 

        set_skill("blade",100);          
        set_skill("parry",70);          
        set_skill("dodge",80);  
        set_skill("perception",30);
        set_skill("combat",90);        
        
        set("talk_reply","只要你不要擾亂附近的武士們就好了....");

        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"說道: 我的武功\最弱，成為依賀三傑之一真是愧\不敢當。\n",
  name()+"說道: 都是因為兩位哥哥的關係呀! \n",
  name()+"說道: 還記得當年我們一起闖天下實在是驚險萬分，真是快樂呀。\n",
(: command("smile") :),
(: command("blush") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "天京井高興的說：好久沒有好好的戰一場了！兩位哥哥請不要插手！\n",
         }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
}



