inherit NPC;

void create()
{
        set_name("公雞",({"cock"}) );
        set("long","一隻公雞，昂著雞冠走來走去。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",2);
        set("level",6);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","腳爪","翅膀"}) ); 
        set("verbs", ({ "bite","claw"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "公雞用腳爪翻動泥土，一邊啄食土裡的小蟲。\n",
        }));                                
        setup();
        add_money("coin",30);
}
