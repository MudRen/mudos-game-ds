inherit NPC;

void create()
{
       set_name("旅人",({"traveler"}));
       set("long","一個旅行者，現在正坐著休息呢！");
       set("gender","男性");
       set("age", 21);
       set("level", 5);

       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("sweat"):),
            (:command("say 別累過了頭，休息一下反而比較好。"):),
            (:command("say 休息是為了走更長遠的路，說的真好，不是嗎？"):)
           }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("walileh"+this_player()->query("id")):),
       "旅客惶恐的說:「我和你無冤無仇，難道為了一點點經驗值就要殺我嗎？」\n"
        }) );
    
        setup();
        add_money("coin", 200);
        carry_object( __DIR__"eq/cloth")->wear();           
}