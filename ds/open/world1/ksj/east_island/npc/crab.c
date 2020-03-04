inherit NPC;

void create()
{
        set_name("螃蟹",({"crab"}) );
        set("long","一隻比手掌還大些的螃蟹，正對著你揮舞著大螯。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",2);
        set("level",4);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體", "右螯", "左螯" }) ); 
        set("verbs", ({ "bite" }) );         
        set("chat_chance", 15);
        set("chat_msg", ({
        "螃蟹邊揮舞雙螯一邊吐著泡沫。\n",
        }));              
        setup();
        add_money("coin",20);
}
