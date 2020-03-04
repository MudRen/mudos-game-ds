inherit NPC;

void create()
{
        set_name("田鼠",({"rat"}) );
        set("long","體形碩大的老鼠，想必吃了不少農作物。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",2);
        set("level",4);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","尾巴"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "田鼠一邊吱吱叫，一邊在土塊間閃躲。\n",
        }));                                
        setup();
        add_money("coin",10);
}
