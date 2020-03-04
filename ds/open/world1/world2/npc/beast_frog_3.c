
inherit NPC;

void create()
{
	set_name("綠皮青蛙", ({"green frog","frog"}) );
	set("long", "一隻綠色的小青蛙，正在這裡跳來跳去的。\n");
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "背部", "後腿", "肚子" })); //受攻部位
	set("verbs", ({ "crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",3);
	set_temp("apply/hit",-20);      //弱化命中率
	set_temp("apply/dodge",-20);    //弱化閃躲率
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		//(: this_object(), "random_move" :),
		"青蛙.咯..咯..的叫了兩聲。\n",
	}));

	setup();
//	carry_object(__DIR__"obj/pork");
}
