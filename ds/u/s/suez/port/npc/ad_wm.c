inherit NPC;

void create()
{
       set_name("冒險者",({"adventuress","woman"}));
       set("long","女性冒險者有不輸給任何男性的能力及企圖心。\n");
       set("gender","女性");
       set("age", random(20)+15);
       set("level", random(10)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say 下次的目標是哪裡呢？"):),
            (:command("say 呼∼上次的冒險真刺激呀！"):),
            (:command("say 該好好休息一下了..."):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("lick"):)
        }) );
    
        setup();

	carry_object( __DIR__"wp/sword")->wield();
         carry_object( __DIR__"eq/l_armor")->wear();  
        carry_object( __DIR__"eq/cloth")->wear();
}

