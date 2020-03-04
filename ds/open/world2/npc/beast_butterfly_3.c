inherit NPC;
void create()
{
	set_name("黑鳳蝶", ({"black butterfly","butterfly" }) );
	set("long",@LONG
一隻十分少見的黑鳳蝶，正在這裡翩翩飛舞。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "觸角", "翅膀" })); //受攻部位
	set("verbs", ({ "bite" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",3);
	set("dex",3);
	set("str",3);
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
