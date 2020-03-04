inherit NPC;

void create()
{
	set_name("小熊", ({ "small bear", "bear" }) );
	set("long", @LONG
一隻大熊的後代, 似乎還沒長大的樣子, 脖子附近還有許多的白毛。
LONG	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "crash","bite", "claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 3);
	set("level", 13);
	set("str", 20);
	set("con", 18);
	setup();
}