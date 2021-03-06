inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name("劍齒貓", ({"saber cat","cat","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
劍齒貓是二足動物的一族，擁有高等的智慧和許多貓科動物的特徵。
劍齒貓會用劍、鏢槍或是投擲性的武器攻擊，牠們的速度很快，而且十分
喜好獵殺。
long
);
        set("title","血腥荒野");
        set("race", "evil");
        set("age", 120);
        set("chat_chance", 8);
        set("chat_msg", ({
                (: random_move :),
        }) );
		set("level", 35+random(5));
        set("attitude", "aggressive");
		set("addition/bio", 3);
        set("addition_armor", 100);
        set("addition_damage", 100);
        set("addition_shield", 100);
        
        /* 戰鬥動作 */
   	 set("chat_chance_combat", 50);
   	 set("chat_msg_combat", ({
      (: do_fight_issue :),        
   	 }) );
      
        set("addition/bio", 3);
        set("addition/wit", 10);
        setup();
        set_living_name("_BLOOD_FIELD_NPC_");

        switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
                carry_object(__DIR__"obj/armor")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/armor")->wear();
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/belt")->wear();
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/ring")->wear();
                carry_object(__DIR__"obj/boots")->wear();
        break;
        }        
        switch( random(2) ) {
                case 0:
                        carry_object(__DIR__"obj/longsword")->wield();
                break;
                case 1:
                        carry_object(__DIR__"obj/spear")->wield();
                break;
        }
        
        carry_object(__DIR__"obj/q_stone");
}


