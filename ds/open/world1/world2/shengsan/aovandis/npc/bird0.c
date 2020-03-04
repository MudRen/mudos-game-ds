
inherit NPC;

void create()
{
	set_name("小小鳥", ({"small bird","bird","small"}) );
	set("long", "一隻灰白色的小鳥，正在這裡飛翔。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "雙足", "翅膀" })); //受攻部位
	set("verbs", ({ "bite","poke" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 2);
	set("level",2);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率

	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
