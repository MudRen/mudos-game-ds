#include <ansi.h>
inherit NPC;

void create()
{
        set_name("星際遊商", ({"traveller seller", "seller","traveller"}) );
        set("long", "他原本是一位終年在星際中旅遊的旅客,由於最近急需旅費
所以開行販賣日常用品.沒想到生意竟然不錯.乾脆轉行成了商人！
他正在採購一些防身的武器\n");
        set("race", "妖魔");
        set("gender", "男性"); 
        set("age", 86);
        set("attitude", "heroson");
        set("level", 5);
        set("evil", -99);
        set("combat_exp",400);
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        "星際遊商在這附近繞了幾繞逛了幾逛「嗯∼∼∼∼」。\n",  
        (:command("say 就算我便宜一點啦！！"):),
        (:command("say 這∼∼嗯∼∼好像蠻不錯的！！！"):),
}) );
        set("chat_chance_combat",16);
        set("chat_msg_combat", ({
        (:command("say 哇........這....這個星球怎麼會這個樣子呢？？？"):),
        (:command(""):),
        }) );
        setup(); 
}

