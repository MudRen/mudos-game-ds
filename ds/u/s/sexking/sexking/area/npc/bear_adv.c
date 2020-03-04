#include <ansi.h>
inherit NPC;
void create()
{
        set_name("進階依賀忍者",({ "adv bear man","bear","man" }));
        set("long",
                "他是一位已進階修行忍術的高強忍者，善常使用暗器。\n"
        );
        set("age",39);
        set("level",26);
        set("gender", "男性");
        set("str",25);                  
        set("dex",65);                  
        set("con",35);                
        set("int",55);  
        set("exp",5342);               
        set("attitude", "peaceful");
        set("combat_exp",3000);         
                        
        set_skill("blade",65);
        set_skill("throwing",65);
        set_skill("parry",30);          
        set_skill("dodge",60);  
        set_skill("perception",10);
        set_skill("combat",60);        
        
        set("talk_reply","沒事。");

        set("chat_chance",20);
        set("chat_msg", ({
  
  name()+"進階後，我要更加油才行。\n",
  name()+"開始盤坐靜思。\n",
  name()+"開始研究手上的忍術密技之卷 。\n",
(: command("hmm") :),
(: command("soga") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "忍者激動的說：我們依賀流忍術是不會被你打倒的！！\n",
         (: command("wiled blade") :),
    }) );
        setup();
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword")->wield();
        carry_object(__DIR__"wp/yi_blade");
        carry_object(__DIR__"eq/bear_cloth")->wear();
}
void die()
{
        message_vision("$N嚥下最後一口氣說:怪只怪我天資愚笨..死也活該\n",this_object());
        ::die();
}

