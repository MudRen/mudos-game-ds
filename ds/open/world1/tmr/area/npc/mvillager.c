inherit NPC;

void create()
{
	set_name("村民",({ "villager" }) );
	set("long","一個居住在孟村的村民，看來並無什麼過人之處。\n");
	set("race","人類");
	set("age",25);
        set("level",3);
	set("attitude","friendly");

	set_skill("dodge",5);
	set_skill("unarmed",5);
      set_skill("bagi_fist",5);
      map_skill("unarmed","bagi_fist");
	setup();
add_money("silver",5);           
}
