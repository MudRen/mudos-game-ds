inherit NPC;

void create()
{
	set_name("老鼠", ({ "mouse" }) );
	set("long", @LONG
一隻小動物, 身形極小, 在你腳旁徘徊, 遊走不離。
LONG	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "crash","bite", "claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 1);
	set("level", 5);
	set("dex", 10);
	setup();
}