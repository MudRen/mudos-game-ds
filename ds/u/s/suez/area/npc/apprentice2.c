inherit NPC;

void create()
{
       set_name("摘星門弟子",({"apprentice"}));
       set("long","一個正用功\練\武的人，為了復興摘星門而努力。\n");
       set("gender","女性");
       set("age", 21);
       set("level", 20);

       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("sweat"):),
            (:command("say 顏師姐好可憐喔！為什麼風師兄要離開，他和顏師姐不是最好嗎？"):),
            (:command("say 唉！幸好那天我們不在，否則哪能在這裡談話呢？"):),
            (:command("say 顏師姊的父親失蹤，風師兄又....唉。"):),
         (:command("say 潘師兄看管的金色猴子好凶，害我都不敢去他那裡學武功…"):),
            (: random_move :),
           }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("slap"+this_player()->query("id")):),
       "摘星門弟子大喊：「你太過分了喔！」\n"
        }) );
    
        setup();
        add_money("coin", 200);
        carry_object( __DIR__"wp/long_dagger")->wield();
       carry_object( __DIR__"eq/cloth")->wear();         

}
