//
#include <ansi.h>
inherit SKILL;

int combine(object me, object target,object *members)
{
	string msg;
	object member,weapon;
	int i,damage,exp;
	
	if( !target ) return 0;

	if(!me->can_fight(target)) return me->can_fight(target);
	
	for(i=0;i<sizeof(members);i++)
	{
	 if(members[i]->query_skill_mapped("unarmed")!="bagi_fist") continue;
	 if(members[i]->is_busy()) continue;
	 weapon=members[i]->query_temp("weapon");
	 if(weapon)
	 {
	  if(weapon->query("skill_type")!="unarmed") continue;
	 }
   	 member=members[i];
	 break;
	}
	 
	if(!member)
	{
	//	message_vision("Combine_attack Error: Can't find member !\n",me);
		return 0;
	}
	
	if(member->query("mp")< 10 || me->query("mp") < 10 ) return 0;

//�Ĥ@���q	
	message_vision("\n"HIY"$N"NOR"�M"HIG"$n"NOR"�洫�F�@�U����, ��M�X�O�I�i���H������!!\n\n\t"HIC"�y��㯫���g���١��z\n\n"NOR,me,member);
	message_vision(HIY"$N"NOR"�a���@�D, "HIG"$n"NOR"���ըϥX"HIC"�y�����z"NOR"�ѫ��N"HIY"$N"NOR"���e�ܥb�Ť�,\n"NOR,me,member);
	member->improve_skill("bagi_fist",1+member->query_int()/2);
	me->improve_skill("godsword",1+me->query_int()/2);
	member->receive_damage("mp",3);
	me->receive_damage("mp",3);
	me->start_busy(1);
	
	if( random(COMBAT_D->attack_factor(member,"unarmed")+30)  > random(-COMBAT_D->dodge_factor(target,"dodge")))
	{
		message_vision("\n����$n�N�`�N�O��b�Ť���, "HIG"$N"NOR"���H�N��{��$n����,\n  �@��"HIW"�y�ժ����x���z"NOR"�N"HIR"$n�_���T��!!\n\n"NOR,member,target);
		damage=member->query_damage() + member->query_skill("bagi_fist")/3;
		damage-=target->query_armor();
		if(damage<10) damage=10;
		target->receive_damage("hp",damage,member);
		member->receive_damage("mp",2);
		target->start_busy(3);
		member->start_busy(1);
		tell_object(member,"  �A�o���B�~��"+damage*3+"�I�g���!\n\n");
		member->add("exp",damage*3);
		member->improve_skill("bagi_fist",1+member->query_int()/3);
	}
//�ĤG���q
	message_vision("����"HIY"$N"NOR"���ĦӤU, ����"HIW"�y½���ЫB�z"NOR"������P�ɵo��,\n"HIR"  �L�ƼC�v�p����멹$n���h, "NOR,me,target);
	if( random(COMBAT_D->attack_factor(me,"sword")+50)  > random(-COMBAT_D->dodge_factor(target,"dodge")))
	{
	 message_vision(HIW"$N�{�פ���, "HIR"�n�ɥֶ}�׺�, ���|�q!!\n\n"NOR,target);
	 damage=me->query_damage() + me->query_skill("godsword")/3;
	 damage-=target->query_armor();
	 if(damage<10) damage=10;
	 target->receive_damage("hp",damage,me);
	 if(!target->is_busy()) target->start_busy(2);
	 me->receive_damage("mp",2);
	 me->start_busy(1);
	 tell_object(me,"  �A�o���B�~��"+damage*3+"�I�g���!\n");
	 me->add("exp",damage*3);
	 me->improve_skill("godsword",1+me->query_int()/3);
	}
	 else
	{
		message_vision("$N�s½�F���ӭo��T�V�����}�o�D�W������!!\n\n",target);
		me->start_busy(1);
	}
	
	if(!target->is_fighting(me)) target->kill_ob(me);
	if(!target->is_fighting(member)) target->kill_ob(member);
	return 1;
}
