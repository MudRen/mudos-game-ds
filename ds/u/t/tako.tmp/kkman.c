inherit NPC;
void create()
{
        set_name("路人",({ "traveller" }));
        set("long","一個正在趕路的路人，他因為趕路，因此背上滿是臭臭的汗味。\n");
        set("level", 1);
        set("age",20);
        set("chat_chance", 15);
        set("chat_msg", ({
  "路人說： 唉∼還有好幾天的路程要走。 \n",  (: random_move :),
}) );
        setup();
        add_money("coin",150);
        carry_object("/u/t/tako/wolf fist")->wield(); 
        }




