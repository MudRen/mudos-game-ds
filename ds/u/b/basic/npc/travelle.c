inherit NPC;
void create()
{
        set_name("路人",({ "traveller","路人" }));
        set("long","一個正在趕路的路人，他因為趕路，因此背上滿是臭臭的汗味。\n")
;
        set("level", 1);
        set("age",20);
        set("chat_chance", 8);
      set("exp",10000000);
        
        setup();
        add_money("coin",1500000);
        
}
