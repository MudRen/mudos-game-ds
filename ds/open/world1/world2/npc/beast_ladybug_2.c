
inherit NPC;

void create()
{
	set_name("小瓢蟲", ({"small ladybug","ladybug","small"}) );
	set("long", "可愛小巧的瓢蟲，正在四處的玩耍。\n");
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "觸角", })); //受攻部位
	set("verbs", ({ "bite","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",2);
	set("str",1);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率

	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
