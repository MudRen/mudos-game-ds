#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"依賀忍者"NOR,({ "bear man","bear","man" }));
        set("long",
                "他是一位修行忍術的忍者，善常使用暗器。\n"
                
        );
        set("age",39);
        set("level",20);
        set("gender", "男性");
        set("str",20);                  
        set("dex",60);                  
        set("con",30);                
        set("int",50); 
        set("exp",3421);                
        set("attitude", "peaceful");
        set("combat_exp",2000);         
                        

        set_skill("throwing",60);   
        set_skill("parry",20);          
        set_skill("dodge",50);  
        set_skill("perception",10);
        set_skill("combat",50);        
        
        set("talk_reply","我在靜思...請別吵我。");

        set("chat_chance",20);
        set("chat_msg", ({
  
  name()+"喃喃念道：扶桑浪人營最強的人藤田彥空，我是一輩子也追不上呀。\n",
  name()+"開始盤坐靜思。\n",
  name()+"開始研究手上的忍術密技之卷 。\n",
(: command("hmm") :),
(: command("soga") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "忍者激動的說：我們依賀流忍術是不會被你打倒的！！\n",
         (: command("baga") :),
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
        carry_object(__DIR__"eq/bear_cloth")->wear();
}
void die()
{
        message_vision("$N嚥下最後一口氣說:怪只怪我天資愚笨..死也活該\n",this_object());
        ::die();
}
