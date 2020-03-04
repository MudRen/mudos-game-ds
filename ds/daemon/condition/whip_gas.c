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
		tell_object(me, HIW"�A�餺��������l�����F�C\n"NOR);
		return 0;
	} 
	else
	{
		msg = "�u��$N����Ÿ�ݡA�f���R�X�@�f�A��A��ӬO��"HIY"�i"CYN"�E��K�X"HIY"�j"NOR"���l�i�A\n";
		msg += "�����z�g�A$N��������z�X�F�@���j�j��������l�I\n\n";
		msg += HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w"HIW"�i"CYN"�E��E�K�M"HIW"�j"HIY"�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
		message_vision(msg, me);
		if( 99/3 + random(100) > random(me->query_skill("dodge")) )
		{
			damage = 100 + random(100) + random(100) - me->query_armor()/2 - random(me->query_armor()/2) - (me->query("con"));
			if(damage<20) damage=15+random(8);
			message_vision(HIR "\n���G�q$N���W�z�X�������W�����a���@�Ѧ��A�ݨӨ��ˤ����C\n" NOR,me);
			me->receive_damage("hp",damage);
			me->receive_damage("ap",random(damage));
			message_vision("\n",me);
			COMBAT_D->report_status(me);
		}
		else
		{
			message_vision(HIW "\n$N�j�奢��A�b�@�����A�i�{�X�@�����Z���\\�O�A����g�I�A����F���W�������~�򬪥X�C\n" NOR,me);
		}
		if( duration > 10 ) duration = 10;
		me->set_temp("temp/death_type", "["HIY"�z�𨭤`"NOR"]");
		me->apply_condition("whip_gas", duration-1 );
	}
	return 1;
}
