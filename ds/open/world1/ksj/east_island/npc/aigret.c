inherit NPC;

void create()
{
        set_name("白鷺鷥",({"aigret"}) );
        set("long","有著雪白的羽毛跟長長的嘴巴，經常出現在農田、河邊覓食。\n");
        set("race", "野獸");    
        set("unit","隻");
        set("age",2);
        set("level",6);
        set("attitude", "heroism");  
        set("limbs", ({ "頭部", "身體","雙腳","翅膀"}) ); 
        set("verbs", ({ "poke" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "白鷺鷥轉過頭去整理翅膀的羽毛。\n",
        }));                                
        setup();
        add_money("coin",20);
}
