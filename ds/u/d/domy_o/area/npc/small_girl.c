inherit NPC;

void create()
{
        set_name("小女孩",({"girl"}) );
        set("long","一位天真可愛的小女孩，正在百貨公司上亂晃。\n");
        set("race", "人類");
           
        set("unit","位");
        set("age",1);
        set("level",1);
        set("str",1);
         set("dex",-1);
         set("attitude","heroism");
         set("chat_chance",3);
        set("chat_msg",({
                "小女孩天真的笑了起來\n",
        }) );

        setup();
        add_money("coin",30);
}
