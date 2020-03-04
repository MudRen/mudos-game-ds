// Npc: /u/l/luky/npc/1.c

inherit NPC;

void create()
{
	set_name("蚊子", ({"mosquito"}) );
	set("long", "可惡的蚊子, 嗡嗡的在你身邊飛來飛去..\n");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "翅膀", "後腳","腹部"})); //受攻部位
	set("verbs", ({ "bite","poke"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level", 1);
	set("con",1);
	set("str",1);
	set("dex",10);
	set("int",1);
	setup();

}
