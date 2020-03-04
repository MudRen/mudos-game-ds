inherit NPC;

void create()
{
	set_name("松鼠", ({"squirrel"}) );
	set("long", @LONG
一隻小動物, 在樹上跑來跑去。
LONG	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "crash","bite", "claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("max_hp",56);
	set("level",2);
	set("dex",3);
	setup();
}