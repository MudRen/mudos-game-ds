#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIW "stormtrooper" NOR , ({"stormtrooper"}) );
	set("long", " 
他上穿著一套輕型的裝甲，和佩帶一枝步槍，
原來他是帝國的軍隊。
\n");
	set("race", "人類");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "heroism");
	set("level", 25);
	set("evil", 30);
	set("combat_exp",3000);
	set_skill("gun",50 );
	set("title",MAG"帝國部隊"NOR);
	set_skill("dodge", 40);
	set_skill("parry", 30);
	set_skill("unarmed",20);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
	(:command("say 去死吧惡賊！！"):),
	(:command("來人啊！有叛軍啊！"):),
	(:command("reload clip"):),
	(:command("ss"):),	
	}) );
	
	
	setup();
	carry_object(__DIR__"wp/blaster")->wield();
	carry_object(__DIR__"wp/bclip");
	carry_object(__DIR__"wp/bclip");
	carry_object(__DIR__"wp/bclip");
	
}

