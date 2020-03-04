// gaoli.c

inherit NPC;

void create()
{
	set_name("高麗商", ({ "gaoli shang", "shang" }));
	set("title", "新羅坊老闆");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long", "這是個高麗商人，長得和中國人沒啥區別。連賣的東西也差不多。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	setup();
}

