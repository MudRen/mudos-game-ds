//god-fire ���Z�u�� (���Z�Ъ�Ūk�N-���t)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,mk;
 
 if(!me) me=this_player();
 inn=me->query_int();
 sk=mk/10+1;
 cost=(mk/3)+10;
 
 if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target )	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	//�ˬd�O�_�i�H����
 if(!me->can_fight(target))
		return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
	    return notify_fail("�A���k�O�����C\n");
	    
 message_vision(HIG"\n$N���Ⱚ�|, �j�ܤ@�n�G�y�@��F�F�P�ڦP�b�I�I�z\n"NOR,me);
 me->start_busy(2); //�I�k�ʧ@�ɶ�
 me->receive_damage("mp",cost);	//�I�k��MP
 me->set_temp("power_cast",2+mk/20);
 call_out("delay",3,target,me,mk);
 return 1;
}

int delay(object target,object me,int mk)
{
	
 int inn,sk,damage;
							
 if(!me) return 0;					
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i���F���ɡC\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 
 message_vision(HIR"\n��M$N�⤤�X�{�@�ӥ��j�����y�A�O�H���������I�I\n\n"NOR,me);
 message_vision(HIG"\n$N�j�ܤ@�n�G�y�������ĤH�A�����a�I�z�H�Y�N��W���y���V�ѪšI�I\n\n"NOR,me,target);

    damage= inn +random(mk+inn);
    damage = damage- target->query_sheild()/2 -random(target->query_sheild());
    if(damage<1) damage=random(inn/2);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
       message_vision(HIC"  �u��$N�Q�ѤW�]�U���q���]��, �h�W���ä�ۡI�I"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
       target->receive_damage("hp", damage, me ); 
       COMBAT_D->report_status(target);		//���target���A
       target->start_busy(1);
    }
    else
	{
                message_vision(GRN"  �u��$N�F�{����A�n���e���k���y���F���ɡz���d��C\n"NOR,target);
	}
 } else message_vision(GRN"  �u���u���F���ɡv�������]��$N, �����G�S���y��$N���@���ˮ`�C\n"NOR,target);


 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 return 1;
}
