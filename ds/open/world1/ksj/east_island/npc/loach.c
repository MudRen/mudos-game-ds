inherit NPC;

void create()
{
        set_name("泥鰍",({"loach"}) );
        set("long","一條滑不溜丟的泥鰍，躲在泥巴裡還真看不太出來。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",1);
        set("level",3);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","尾巴"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "泥鰍在水中翻滾一陣，水裡變得污濁不清。\n",
        }));                                
        setup();
        add_money("coin",10);
}
