#include <ansi.h>
inherit NPC;

void create()
{
        set_name("酒鬼" , ({"drinker"}) );
set("long", "一個中年的男子，他每天也來到這裡喝酒。\n");       
        set("race", "人類");
        set("gender", "男性"); 
      set("title",WHT"『今朝有酒今朝醉』"NOR);
        set("age",45); 
        set("attitude", "friendly");
        set("level", 15);
        set("evil", -10);
        set("combat_exp",300);
    set("chat_chance", 2 );  
  set("chat_msg", ({       
(:command("say 好酒~~~好酒~~~"):),  
"酒鬼拿起了一瓶威士忌，一口便喝下去\n",
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        "酒鬼大叫：救命~~~~有人想殺我\n",
        }) );
        setup();
        
}

