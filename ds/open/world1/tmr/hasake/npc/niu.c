
inherit NPC;

void create()
{
    set_name("野牛", ({ "cow" }) );
	set("race", "beast");
	set("age", 5);
	set("level", 2);
    set("long", "一頭健壯的牛。\n");
	set("attitude", "peaceful");
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
    set("verbs", ({ "kick", "bite" }) );


	setup();
}