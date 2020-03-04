inherit NPC;

void create()
{
        set_name("小廚師",({"cook"}) );
        set("long","一位非常認真炒菜的小廚師。\n");
        set("race", "人類");
        
        set("unit","位");
        set("age",1);
        set("level",10);
        set("str",5);
         set("dex",5);
         set("attitude","heroism");
         set("chat_chance",5);
        set("chat_msg",({
                "小廚師正努力的炒起菜來\n",
        (:command("say 得趕快炒好菜才行~~"):),
        (:command("sweat"):),
        }) );

        setup();
        add_money("coin",30);
}
