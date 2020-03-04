inherit NPC;

void create()
{
        set_name("田蛙",({"frog"}) );
        set("long","巴掌大的青蛙，一副跳不太動的樣子。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",1);
        set("level",3);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","前腳","後腳"}) ); 
        set("verbs", ({ "crash" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "田蛙鼓起雙頰，嘓∼嘓∼地叫著。\n",
        }));                                
        setup();
        add_money("coin",10);
}
