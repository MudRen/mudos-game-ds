#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "小女孩" , ({"child"}) );
set("long", "一個十幾歲的小女孩，現在正和其他小孩跑來跑去ㄉ煩死ㄌ，原來她在玩捉迷藏﹏。\n");       
        set("race", "人類");
        set("gender", "女性"); 
        set("age",11); 
        set("env/wimpy", 80);        
        set("attitude", "friendly");
        set("level", 2);
        set("evil", -30);
        set("combat_exp",300);
        set_skill("sword", 2); 
        set_skill("blade", 1);
        set_skill("unarmed", 3);
        set_skill("dodge", 3);
        set_skill("parry", 3); 
    set("chat_chance", 2 );  
  set("chat_msg", ({       
"小女孩一下又跑走ㄌ\n",
(:command("say Got You！！！"):),  
(:command("cac"):),
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        (:command("cry"):),
        }) );
        setup();
        
}

