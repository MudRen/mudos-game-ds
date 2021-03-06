/**
 *	Shadow's mob - 食屍犬
 */
#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "食屍犬", ({ "eat-corpse dog", "dog"}) );
	set("race", "野獸");

	set("level", 10+random(5));
	set_skill("dodge", 80+random(20));
	set_skill("unarmed", 70);
	set_skill("combat", 60);
	set_temp("apply/armor", 200);     /* 附加物理性防護力 */
	set("limbs", ({ "頭部", "身體", "前腳", "後腳" }) ); 
	set("verbs", ({ "bite"}) );  /* 攻擊方式: 咬*/

	set("long", @LONG
    一頭凶猛的惡犬，偌大的身軀與家犬有如天壤之別。碧綠的眼珠
透露出幾分詭異，嘴巴還叼著一根人的手骨，帶有血跡的牙齒異常尖
銳，若被咬上一口肯定會吃不消！
LONG
	);
	set("title", HIY"亂葬崗"NOR);
	set("age", 5+random(5));
	set("evil", 3+random(3));
	set("chat_chance", 4);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("attitude", "killer");
	set("chat_chance_combat", 15);
	
	setup();
	set_living_name("GraveyardWar");
}

void init()
{
	::init();
	if(!this_object()->visible(this_player())) return;
	if(this_player()->query("level") > 10 && userp(this_player()))
		this_object()->kill_ob(this_player());
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
	::die();
	return;
}
