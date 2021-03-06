//whip_gas.c
//for skills masen_whip.c
//write by alickyuen

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;
	string msg;
	if( !duration )
	{
		tell_object(me, HIW"你體內的黃金氣勁消失了。\n"NOR);
		return 0;
	} 
	else
	{
		msg = "只見$N渾身顫抖，口中吐出一口鮮血，原來是剛"HIY"【"CYN"九荒八合"HIY"】"NOR"的餘波，\n";
		msg += "金光爆射，$N的身體裡爆出了一條強大的黃金氣勁！\n\n";
		msg += HIY"─────────────"HIW"【"CYN"九荒•八和"HIW"】"HIY"──────────────→\n";
		message_vision(msg, me);
		if( 99/3 + random(100) > random(me->query_skill("dodge")) )
		{
			damage = 100 + random(100) + random(100) - me->query_armor()/2 - random(me->query_armor()/2) - (me->query("con"));
			if(damage<20) damage=15+random(8);
			message_vision(HIR "\n結果從$N身上爆出的金光上隱隱帶有一股血氣，看來受傷不輕。\n" NOR,me);
			me->receive_damage("hp",damage);
			me->receive_damage("ap",random(damage));
			message_vision("\n",me);
			COMBAT_D->report_status(me);
		}
		else
		{
			message_vision(HIW "\n$N大驚失色，在一瞬間，展現出一身不凡的功\力，順手狂點，阻止了身上的金光繼續洩出。\n" NOR,me);
		}
		if( duration > 10 ) duration = 10;
		me->set_temp("temp/death_type", "["HIY"爆氣身亡"NOR"]");
		me->apply_condition("whip_gas", duration-1 );
	}
	return 1;
}
