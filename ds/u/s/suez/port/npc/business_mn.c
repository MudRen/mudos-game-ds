inherit NPC;

void create()
{
       set_name("商人",({"businessman","man"}));
       set("long","在海上從事貿易的商人。\n");
       set("gender","男性");
       set("age", random(20)+20);
       set("level", random(5)+1);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say 好忙好忙！！"):),
            (:command("say 那邊小心點！別碰傷了！"):),
            (:command("say 那筆錢數目對嗎....？"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("fear"):)
        }) );
    
        setup();
        switch(random(5))
        {
        case 1: carry_object( __DIR__"eq/cloth")->wield();break;
        case 2: carry_object( __DIR__"eq/rich_cloth")->wear();break;   
        case 3: carry_object( __DIR__"eq/cloth")->wear();
                carry_object( __DIR__"wp/staff")->wield();break;   
        case 4: carry_object( __DIR__"eq/rich_cloth")->wear();
                carry_object( __DIR__"wp/staff")->wield();break; 
        default:break;
        }
        
        add_money("coin", random(1000));
}

