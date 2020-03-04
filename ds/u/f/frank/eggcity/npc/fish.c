inherit NPC;

void create()
{
        set_name("鯉魚",({"fish"}) );
      set("long","一條普通的小魚，正快樂的悠游。\n");
        set("race", "野獸");    
        set("env/wimpy", 10);   
        set("unit","條");
        set("age",2);
        set("level",2);
        set("attitude", "heroism");  
      set("str",1);
      set("con",1);
        set("limbs", ({ "頭部", "身體", "前鯕", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite" }) );                         //攻擊方式
        set("chat_chance",6);
        
        setup();
        add_money("coin",10);
}

