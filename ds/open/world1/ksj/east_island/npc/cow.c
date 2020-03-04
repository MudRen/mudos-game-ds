inherit NPC;

void create()
{
        set_name("乳牛",({"cow"}) );
        set("long","一隻成年的乳牛，正在垂著頭吃草。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",5);
        set("level",15);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","前腳","後腳","尾巴"}) ); 
        set("verbs", ({ "hoof","crash"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "乳牛咬了一把青草，慢條斯理地嚼食著。\n",
        }));                                
        setup();
        add_money("coin",200);
}
