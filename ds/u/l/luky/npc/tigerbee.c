
inherit NPC;

void create()
{
	set_name("虎頭蜂", ({"tiger bee","bee"}) );
	set("long", "一隻兇猛的虎頭蜂, 正瘋狂的攻擊任何侵入牠地盤的生物。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "翅膀", "尾部" })); //受攻部位
	set("verbs", ({ "bite","poke"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",3);
	set("dex",7);
	set("str",5);
	set("attitude", "killer");
	setup();

}
