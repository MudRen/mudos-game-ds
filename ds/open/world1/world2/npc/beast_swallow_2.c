
inherit NPC;

void create()
{
	set_name("小燕子", ({"small swallow","swallow","small"}) );
	set("long",@LONG
一隻體態輕盈的燕子，正在這裡盤旋。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "雙足", "翅膀" })); //受攻部位
	set("verbs", ({ "bite","poke" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",2);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
