inherit NPC;

void create()
{
       set_name("小流氓",({"small hoodlum","hoodlum"}));
       set("long","這個衣裝不整,手中拿一把小刀的少年,看起來只十四、五歲,就像是逃家的不良少年。\n");
       set("gender","男性");
       set("age", 14);
       set("level", 5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("snort"):),
            (:command("say 嘿嘿∼照子放亮點，別在這裡皂囉！！"):),
            (:command("say 看什麼看！！再看挖出你兩隻照子！！"):),
         (:command("say 呸！什麼東西！！"):),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       "小流氓喝道：「我今天不好好教訓你一頓！我.....%$#@^&」\n"
        }) );
    
        setup(); 
       carry_object( __DIR__"wp/knife")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}