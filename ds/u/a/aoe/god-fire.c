//god-fire ���Z�u�� (���Z�Ъ�Ūk�N-���t)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,mk;
 
 if(!me) me=this_player();
 inn=me->query_int();
 mk=me->query_spell("god-fire");
 sk=mk/10+1;
 cost=(mk/3)+10+random(me->query("level"));
 
 if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target )	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	//�ˬd�O�_�i�H����
 if(!me->can_fight(target))
		return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
	    return notify_fail("�A���k�O�����C\n");
	    
 message_vision(HIG"\n$N����X�Q�A���ۻy�D�G�u�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC�v\n"NOR,me);
 me->start_busy(2); //�I�k�ʧ@�ɶ�
 me->receive_damage("mp",cost);	//�I�k��MP
 me->set_temp("power_cast",2+mk/20);
 call_out("delay",3,target,me,mk);
 return 1;
}

int delay(object target,object me,int mk)
{
	
 int inn,sk,damage,shield,level;
							
 if(!me) return 0;					
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 level=me->query("level");
 message_vision(HIR"\n��M$N��W�P�K�Ĥ�,�����q��ް_�@�D�u���Z�u���v�I�I\n\n"NOR,me);
 message_vision(HIG"\n$N�q���@�n�u���v�A�H�Y���_��W�u�����N�V$n�I�I\n\n"NOR,me,target);
 shield=target->query_sheild();

    damage = mk*2+inn*3+level*3;
    damage = damage/2 + random(damage/2);
    damage = damage - shield/2 -random(shield);
    if(damage<1) damage=random(inn*2);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
	// �W�[�����ˮ`���v�T
	damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me ); 
       message_vision(HIC"  �u��$N�{�������@�D�u���Z�u���v����աA�Q�N�o�ֶ}�׺�I"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
       COMBAT_D->report_status(target);		//���target���A
    }
    else
	{
       		message_vision(GRN"  �u��$N�F�{����A�n���e�����}�@�D�u���Z�u���v���r�P��աC\n"NOR,target);
	}
 } else message_vision(GRN"  �u���Z�u���v�r�P���N�V$N, �����G�S���y��$N���@���ˮ`�C\n"NOR,target);


 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 return 1;
}
