inherit NPC;

void create()
{
        set_name("小乳牛",({"small cow","cow"}) );
        set("long","三個月大的小乳牛，看起來莽莽撞撞的。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",1);
        set("level",10);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","前腳","後腳","尾巴"}) ); 
        set("verbs", ({"hoof","crash"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "小乳牛不時興奮地又跑又蹬。\n",
        }));                                
        setup();
        add_money("coin",100);
}
