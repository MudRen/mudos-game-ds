#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("星際古董商", ({"traveller Antiquer","antiquer"}) );
        set("long", "一位專門收集散落在星際中一些”無ㄟ摸ㄟ”的奇異商人，他所賣
的東西看起來挺奇異而且都蠻沒用的，不過有空的話你倒可以看
看他倒底在賣些甚麼，說不定你會有意外的收穫ㄛ。
PS無ㄟ磨ㄟ=有的沒的的臺語\n"); 
        set("limbs", ({ "頭部", "身體", "腳", "右手","左手","胸口" }) );     　  set("verbs", ({ "hoof","crash" }));  
        set("race", "妖魔");
        set("gender", "男性"); 
        set("age", 80);
        set("attitude", "heroson");
        set("level", 7);
        set("evil", -99);
        set("combat_exp",700); 
        set("storeroom","/u/z/zorg/area/shop"); //注意. 要建立一個room放東西
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        "星際古董商爆吼道：來∼呦∼∼來∼呦！！！。\n",  
        "星際古董商爆吼道：便∼∼∼宜∼∼∼賣呦！！！。\n",  
        (:command(""):),
}) );
        set("chat_chance_combat",16);
        set("chat_msg_combat", ({
        (:command("say 哇............"):), 
        "星際古董商爆吼道：打∼∼劫∼∼阿！！。\n",  
        "星際古董商爆吼道：救∼∼人∼∼啦！！！。\n",  
        }) );
        setup(); 
}
void init()
{
        add_action("do_sell","sell");
        add_action("do_list","list");
        add_action("do_buy","buy");
}



