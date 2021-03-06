#include <ansi.h>
inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name(HIC"荒野土司"NOR, ({ "field toast", "toast", "_BLOOD_FIELD_NPC_" }) );
        set("long",@long
有些像教徒般的生物，會以和他們身軀差不多的刀來攻擊，小土人原
本是叢林中的居民，一般稱為他們為食人族，身體較小、十分聰明的生物
，單獨的小土人十分脆弱而且可以輕易打倒。而土人族群中的荒野土司更
是自然元素的擅長者，並且會呼朋引伴來攻擊招惹他們的人。
long
);
        set("title", HIR"血腥荒野"NOR);
        set("race", "evil");
        set("age", 300);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
	      	(: do_fight_help :),        
			(: do_fight_heal :),      
        }) );

        set("attitude", "aggressive");
        set("addition/bar", 5);
        set("addition/wit", 5);
        set("addition_armor", 100);
        set("addition_damage", 150);
        set("addition_shield", 200);
          set("level", 40+random(5));

        setup();
        set_temp("apply/hit", 50);

        carry_object(__DIR__"obj/wizard_hat")->wear();
        carry_object(__DIR__"obj/wizard_gloves")->wear();
        carry_object(__DIR__"obj/wizard_pants")->wear();

        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
}


