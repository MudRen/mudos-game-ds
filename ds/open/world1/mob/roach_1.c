
inherit NPC;

void create()
{
	set_name("小蟑螂", ({"small cockroach","cockroach","roach"}) );
	set("long",@LONG
一隻咖啡色的小蟑螂, 正在地上爬來爬去。
LONG
);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "翅膀", "後腳","腹部"})); //受攻部位
	set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",1);
	set("str",1);
	set("hp",5);
	setup();
	set_element("ground"); //none,wind,ground,fire,metal,plant,water,
}
