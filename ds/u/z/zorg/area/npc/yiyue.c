#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "倚月" , ({"yi yue","yi","yue","yiyue"}) );
        set("long",
"你眼前是一位充滿靈氣的女孩，她苗佻的身驅似乎讓你可以感覺到它的柔軟，
又覺得她的一頭柔髮若有若無的撫在你的臉上使你有一種虛幻的感覺，
不由得使的你心下一片茫然。當你試著去看她的臉，你只見半邊的臉蛋，
一弘如水的眼睛，雖然側影看不清楚，但顯然容貌秀麗絕倫。\n");       
        set("race", "人類"); 
        set("gender", "女性"); 
        set("age",17); 
        set("env/wimpy", 45);        
        set("attitude", "friendly");
        set("level", 12+random(5)+random(5));
        set("evil", -999);
        set("combat_exp",2500);
    set("chat_chance", 3 );  
  set("chat_msg", ({   
(: this_object(), "random_move" :),     //會自己走動
"倚月長長的嘆了一口氣\n"
"倚月淡淡的對你一笑\n" 
   }) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({ 
        (:command("say ..."):),
        (:command("angry"):),
        }) );
        setup(); 
        carry_object(__DIR__"eq/ring.c")->wear();
        carry_object(__DIR__"eq/boots.c")->wear();
}


