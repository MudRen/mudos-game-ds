
inherit NPC;

void create()
{
	set_name("小蝴蝶", ({"small butterfly","butterfly","small"}) );
	set("long", "一隻白色的小蝴蝶，正在這裡飛舞。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "觸角", "翅膀" })); //受攻部位
	set("verbs", ({ "bite" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",1);
	set("dex",2);
	set("str",1);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率

	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
