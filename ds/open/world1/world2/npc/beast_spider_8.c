#include <ansi.h>
inherit NPC;

void create()
{
	set_name("人面蜘蛛", ({"face pattern spider","spider"}) );
	set("long", "一隻背部有著人面花紋的巨大蜘蛛，正虎視眈眈的瞪著你。\n");
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前足", "後足", "腹部" })); //受攻部位
	set("verbs", ({ "bite","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 2);
	set("level",8);
	set_temp("apply/hit",-20);      //弱化命中率
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();
}
int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIW"$N對$n吐出一堆黏液，"NOR,me,victim);
	if(hitrole > 100)
	{
		message_vision(HIW"$n閃躲不及而被黏液噴中，動彈不得。\n"NOR,me,victim);
		victim->start_busy(2);
		return 1;
	}
	else message_vision(HIW"但被$n機警的閃了過去。\n"NOR,me,victim);
	return 0;
}
