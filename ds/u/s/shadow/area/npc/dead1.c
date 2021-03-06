/**
 *	Shadow's mob - 活死人
 */

#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "活死人", ({ "living dead", "dead", "living" }) );
	set("level", 10+random(10));
	set_skill("dodge", 50+random(50));
	set_skill("unarmed", 90);
	set_skill("combat", 80);
	set_temp("spell/armor", 200);     /* 附加物理性防護力 */
	
	set("long", "一個半死不活的死人。\n");
	set("title", HIG"義莊"NOR);
	set("age", 20+random(50));
	set("evil", 3+random(3));
	set("chat_chance", 4);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("wimpy", 50);
	set("attitude", "killer");
	set("chat_chance_combat", 15);
	set("chat_msg_combat",({
		"活死人表情呆滯地看著你，詭異的表情看得你頭皮發麻∼\n",
		(: command("say ∼ 還 我 命 來 ∼\n") :),
		(: command("ghost") :),
	}));
	
	setup();
	add_money("coin", random(500));
	set_living_name("GraveyardWar");
}

void init()
{
	object ppl = this_player();
	::init();
	if ( !this_object()->visible(ppl) ) return;
	if ( (ppl->query("level") > 10) && userp(ppl) )
		this_object()->kill_ob(ppl);
}

void die()
{
	int i;
	object ob;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	if (random(3) == 1)	{ 
		ob->add("popularity", 1);
		tell_object(ob,HIW"(因為你消滅了活死人，你獲得了 1 點聲望。)\n"NOR);
	}
	
	::die();
	return;
}
