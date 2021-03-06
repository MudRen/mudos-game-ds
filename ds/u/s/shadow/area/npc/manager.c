/**
 *	Shadow's mob - 管理員
 */
#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "管理員", ({ "graveyard manager", "manager" }) );
	set("level", 30);
	set_skill("dodge", 80);
	set_skill("unarmed", 100);
	set_skill("combat", 100);
	
	set("long", @LONG
    一個奇怪的老頭，呆滯的表情讓人頭皮一震發麻。肩上扛著一隻
已經生滿了鏽的鋤頭，身上的衣服與頭上的斗笠都沾滿了黃土，讓你
聯想到似乎這奇怪的老頭是剛從土裡爬出來的感覺！
LONG
	);
	set("title", HIG"義莊"NOR);
	set("age", 83);
	set("evil", 0);
	set("attitude", "killer");
	set("chat_chance_combat", 15);
	set("chat_msg_combat",({
		HIG"義莊管理員面無表情地望著你∼\n"NOR,
		(: command("ghost") :),
	}));
	
	setup();
	add_money("coin", 800);
	set_living_name("GraveyardWar");
}

void init()
{
	::init();
	if(!this_object()->visible(this_player())) return;
}

void die()
{
	object ob, ghost, room, env, npc;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	::die();
	return;
}
