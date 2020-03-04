inherit NPC;

void create()
{
        set_name("小魚",({"small fish","fish"}) );
        set("long","一條小魚，正在水中敏捷地游來游去。\n");
        set("race", "野獸");    
        set("unit","條");
        set("age",2);
        set("level",2);
        set("attitude", "heroism");  
        set("str",1);
        set("con",1);
        set("limbs", ({ "頭部", "身體", "前鰭", "尾巴" }) ); 
        set("verbs", ({ "bite" }) );                       
        setup();
        add_money("coin",10);
}

