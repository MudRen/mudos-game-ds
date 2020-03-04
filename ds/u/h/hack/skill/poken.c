#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target ) return notify_fail("對誰施展波動拳?\n");
	if((int)me->query("mp") < 20 )
		return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
	
	if(!me->can_fight(target))
		return me->can_fight(target);
	
	message_vision("\n"HIW" 『波∼∼』 $N將雙手並於身後, 雙眼緊盯著$n, 全身的力量逐漸集中於一點..\n"NOR,me,target);
	me->add("mp", -20);
	me->start_busy(2);
	me->set_temp("power_exert",1);	//這個值在受到攻擊時會減 1 ..
	call_out("delay",3,me,target);
	return 1;
}

int delay(object me,object target)
{
	int damage;
	if(!me) return 0;
	if(!me->query_temp("power_exert") || me->query_temp("power_exert") < 1) 
	{
	 message_vision(HIW"$N"HIW"因為受到傷害而亂了真氣, 無法順利施展波動拳。\n"NOR,me);
	 return 1;
	}
	me->delete_temp("power_exert");
	//敵人消失(死亡)
	message_vision(HIW"\n『∼∼波動拳∼∼』　只見$N"HIW"猛然將雙手疾風般往前推出﹗\n"NOR,me);
	if(!target)
	{
	 message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般呼嘯而過, 瞬間消失於彼方。\n"NOR,me);
	 return 1;
	}
	//敵人離開
	if(environment(me)!=environment(target))
	{
	 message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般呼嘯而過, 瞬間消失於彼方。\n"NOR,me);
	 return 1;
	}
	//閃過
	if( random(me->query_dex()+me->query_skill("poken")) < random(target->query_dex()))
	{
	 target->improve_skill("dodge",3);
	 me->improve_skill("poken",1+random(me->query_int()/6));
	 message_vision(HIW"一顆由內力聚集而成的氣彈如砲彈般從$N"HIW"身旁呼嘯而過。\n"NOR,target);
	 if(!target->is_fighting(me)) target->kill_ob(me);	//反擊
	 return 1;
	}
	//命中
	damage = 20 + me->query_skill("poken")*2;
	damage -= target->query_armor();
	if(damage < 30) damage = 30;
	if(damage > 200) damage =200;
	message_vision(HIW"一顆由內力聚集而成的氣彈砲彈般猛烈的擊向$N, $N"HIW"被震的氣血翻騰, 臉色慘然。\n"NOR,target);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
	target->receive_damage("hp", damage, me );
	if(!me->is_fighting(target)) me->kill_ob(target);	//攻擊性技能加上這行
	if(target->query("hp")>0)
	{
  		if(!target->is_fighting(me)) target->kill_ob(me);	//攻擊性技能加上這行
		COMBAT_D->report_status(target);
	}
	me->improve_skill("poken",1+me->query_int()/10);
	target->start_busy(1);
	return 1;
}

