inherit NPC;

void create()
{
       set_name("水手",({"waterman","man"}));
       set("long","黝黑的皮膚，豪爽的笑聲，這是一位勇敢的海上男兒。\n");
       set("gender","男性");
       set("age", random(20)+15);
       set("level", random(5)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say 等下來喝一杯吧！！"):),
            (:command("say 嘿！上次我遇到那個才恐怖呢！"):),
            (:command("say 喂！借過！借過一下喲！"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("snort"):)
        }) );
    
        setup();
        carry_object( __DIR__"wp/waterman_knife")->wield();
        if(random(50)>random(500)) carry_object( __DIR__"eq/waterman_dress")->wear();  
         else{carry_object( __DIR__"eq/waterman_cloth")->wear();} 

}

