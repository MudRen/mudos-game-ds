#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("野貓", ({ "crazy cat", "cat", "animal-war-object" }) );
	set("long", @LONG
一隻眼露兇光, 邪氣四溢的野獸。
LONG	);
	set("title", HIY"狂"NOR); // War 的 Mob
	set("unit","隻");
	set_living_name("animal-war-object");

	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳" })); //受攻部位
	set("verbs", ({ "crash","bite", "claw", "hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 30);
	set("level", 26);
	set("str", 45);
	set("con", 58);
	set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");

}