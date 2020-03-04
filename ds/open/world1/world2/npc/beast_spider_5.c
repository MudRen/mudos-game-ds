inherit NPC;
void create()
{
	set_name("灰蜘蛛", ({"grey spider","spider"}) );
	set("long", "一隻灰色的大蜘蛛，正在牠的蜘蛛網上睡覺。\n");
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前足", "後足", "腹部" })); //受攻部位
	set("verbs", ({ "bite","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",5);
	set_temp("apply/hit",-20);      //弱化命中率
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));
	setup();
}
