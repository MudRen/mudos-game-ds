inherit NPC;

void create()
{
	set_name("大熊", ({"big bear", "bear" }) );
	set("long", @ABC
一隻龐大的動物, 一隻腳就是你一個人一般的大, 看起來皮厚力大的樣子。
ABC	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳", "腹部"})); //受攻部位
	set("verbs", ({ "crash","bite", "claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 20);
	set("level", 20);
	set("str", 24);
	set("con", 32);
	set("attitude", "aggressive" );
	setup();
}