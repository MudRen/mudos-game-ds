inherit NPC;

void create()
{
        set_name("野狗", ({ "dog" }) );
        set("long", "一隻渾身髒兮兮的野狗。\n");
        set("race", "野獸");
        set("gender","雌性");   // 1999.2.28 增加此註解
        set("age", 3);
        set("level",2);
        
        set("str", 14);
        set("dex", 16);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "野狗用鼻子聞了聞你的腳。\n",
                "野狗在你的腳邊挨挨擦擦的﹐想討東西吃。\n",
                "野狗對著你搖了搖尾巴。\n",
                "野狗用後腿抓了抓自己的耳朵。\n" }) );
                
        set_temp("apply/damage", 10);   //附加傷害力
        set_temp("apply/hit", 10);      //附加命中率
        set_temp("apply/armor", 3);     //附加防禦力 

        setup();
}



