inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name("刺木魔", ({ "thorned hulks","hulks","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
刺木魔大多居住在樹林之中，也是最早期保護叢林的種族。除了它們
的力量和佈滿尖刺的身體以外，現在也淪落為邪惡意志的爪牙。
long
);
        set("title","血腥荒野");
		set("race","evil");
        set("age", 220);
        set("level", 40 + random(5));
        set("chat_chance", 8);
        set("chat_msg", ({
                (: random_move :),
        }) );
		/* 戰鬥動作 */
	   	 set("chat_chance_combat", 50);
	   	 set("chat_msg_combat", ({
	      (: do_fight_issue :),        
	   	 }) );

        set("attitude", "aggressive");
        set("addition/bar", 5);
        set("addition/bio", 3);
        set("addition/wit", 10);
        set("addition_armor", 100);
        set("addition_damage", 150);
        set("addition_shield", 200);

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
          carry_object(__DIR__"obj/bone_hammer")->wield();        
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
}

