inherit NPC;

void create()
{
        set_name("小土人", ({ "fetish","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
有些像教徒般的生物，會以和他們身軀差不多的刀來攻擊，小土人原
本是叢林中的居民，一般稱為他們為食人族，身體較小、十分聰明的生物
，單獨的小土人十分脆弱而且可以輕易打倒。
long
);
        set("title","血腥荒野");
		set("race","evil");
        set("age", 80);
        set("level", 25+random(5));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("attitude", "aggressive");

        setup();
        set_living_name("_BLOOD_FIELD_NPC_");

          switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/armor")->wear();
        break;
        }        
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
}

