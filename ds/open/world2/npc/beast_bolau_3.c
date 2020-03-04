
inherit NPC;

void create()
{
	set_name("伯勞鳥", ({"bolau bird","bird"}) );
	set("long",@LONG
一隻褐色的伯勞鳥，正忙著抓蟲吃。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "雙足", "翅膀" })); //受攻部位
	set("verbs", ({ "bite","poke" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",3);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率
	set_temp("fly",1);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));

	setup();

}
