// venomsnake.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毒蛇", ({ "snake" }) );
	set("long","一隻昂首吐信的青竹絲正虎視眈眈地盯著你。\n");
	set("level",30);
	set("race","野獸");
	set("age", 3);
	set("pursuer", 1);	// mob 會追玩家


	set("limbs", ({ "頭部", "身體", "尾巴" }) );
	set("verbs", ({ "bite" }) );


        set("chat_chance",60);
        set("chat_msg",({
           (:command,"east":),
           (:command,"west":),
           }));

	setup();
}

int hit_ob(object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("poison") < 10 ) {
		ob->apply_condition("poison", 20);
		tell_object(ob, HIG "你覺得被咬中的地方一陣麻癢﹗\n" NOR );
	}
}   

