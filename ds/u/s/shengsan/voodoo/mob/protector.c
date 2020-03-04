#include <path.h>
inherit NPC;

void create()
{
	set_name("護法", ({"protector"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",64);
	set("age", 32);
	set("long", "他正在保護教主的安全\n");
        set_skill("unarmed", 70);
        set_skill("dodge", 150);
	set_skill("whip", 120);

	setup();

	add_money("coin",500);
	carry_object(SHENGSAN+"voodoo/eq/goldwhip")->wield();
}

void init()
{
  if (this_player()->query_temp("voodoo")==1)
  {
	command("say 可惡的賊人, 看我來收拾你.\n");
	kill_ob(this_player());
  }
}
