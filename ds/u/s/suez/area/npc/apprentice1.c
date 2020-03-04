inherit NPC;

void create()
{
       set_name("摘星門弟子",({"apprentice"}));
       set("long","一個正用功\練\武的人，為了復興摘星門而努力。\n");
       set("gender","男性");
       set("age", 21);
       set("level", 20);

       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("sweat"):),
            (:command("say 風師兄也真是的，竟然把我們摘星門放著不管！"):),
         (:command("say 想要升為進階等級就要到泉水那敲石頭。"):),
           (:command("say 顏師姊的父親一招無上大手印可厲害的很﹗聽說可以將石頭打出一個掌印。"):),
          (:command("say 聽說....顏師姊的父親曾經有人看到他往古北林去，然後就再也沒出現過了。"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("angry"+this_player()->query("id")):),
       "摘星門弟子大喊：「可惡！竟敢如此！」\n"
        }) );
    
        setup();
        add_money("coin", 200);   
       carry_object( __DIR__"wp/long_dagger")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}
