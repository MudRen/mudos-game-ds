#include <ansi.h>
inherit NPC;

void create()
{
        set_name("蘇育賢", ({"Daniel Su","su","daniel","daniel su","Su","Daniel"}) );
     set("long", "他的眼睛不時的瞪著你，且試著要撞你一撞，使你愈瞧他怒氣愈盛，
到最後竟然生出一股欲殺之而後快的感覺。\n");
        set("race", "人類");
        set("gender", "男性"); 
        set("age", 15);
        set("attitude", "friendly");
        set("level", 2);
        set("level", 2);
        set("evil", 999);
        set("combat_exp",180);
        set("title",HIW"【"HIG"大"HIR"痞"HIC"子"HIW"】"NOR);
        set("chat_chance",5);  
        set("chat_msg", ({   
        "痞子蘇用很奇怪的眼神瞪你\n",
        "痞子蘇用十分白癡的動作撞了你一下\n",
        "痞子蘇對你吐出了一些異形似的不明唾液\n",
        "痞子蘇白癡的呵呵大笑另你覺的他是不是有問題\n",
        (:command("get all"):),
        (: this_object(), "random_move" :),     //會自己走動 
}) ); 
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({ 
        "痞子蘇哭到: I am going to tell my mom!!!\n",
        (:command("cry"):),
        }) );
       setup(); 
}


