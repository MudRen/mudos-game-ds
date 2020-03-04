
inherit NPC;

void create()
{
	set_name("貓頭鷹", ({"owl"}) );
	set("long",@LONG
一隻眼睛睜的大大的白色貓頭鷹，牠似乎不太歡迎你的到來。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "雙足", "翅膀" })); //受攻部位
	set("verbs", ({ "bite","poke","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",5);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率

	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
