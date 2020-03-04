
inherit NPC;

void create()
{
	set_name("蝸牛", ({"snail"}) );
	set("long", "一隻很可愛的小蝸牛, 正吃力的爬著。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "硬殼" })); //受攻部位
	set("verbs", ({ "bite","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 2);
	set("level",2);
	set("dex",1);
	set("str",4);
	setup();

}
