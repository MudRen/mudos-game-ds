// mind_beast.c

inherit NPC;

void create()
{
	set_name("觀想獸", ({ "mind beast", "beast" }) );
	set("race", "野獸");
	set("age", 3);
	set("long", "這是一隻由修道人的雜念綺思所化的觀想獸﹐會纏住人的魂魄。\n");
	
	set("str", 48);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);

	setup();
}

