
inherit NPC;

void create()
{
	set_name("廚師", ({"cook"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",30);
	set("age", 45);
	set("evil",5);
	set("long", "他是一位廚藝精湛的廚師，負責全巫毒教的飲食。\n");
           
	setup();
	
}
