inherit NPC;

void create()
{
	set_name("小貓", ({"cat"}) );
	set("long", "一隻滿身污垢的小動物。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "尾巴", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "bite","claw","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",2);
	set("max_hp",30+random(10));
	set("dex",5);
	setup();
}
