// tiejiang.c

inherit NPC;

void create()
{
	set_name("鐵匠", ({ "tiejiang", "smith" }));
	set("title", "鐵匠鋪老闆");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long","這位鐵匠正在叮叮噹當地打著鐵，發現你在注視著他，就抬起頭來微笑了一下。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	setup();
}

