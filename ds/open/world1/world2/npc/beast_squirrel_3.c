inherit NPC;
void create()
{
	set_name("松鼠", ({"squirrel"}) );
	set("long",@LONG
一隻可愛的小動物，從牠毛茸茸大尾巴可以看出牠是一隻松鼠。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "尾巴", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "bite","claw","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 2);
	set("level",3);
	setup();

}
