//god-fire ���Z�u�� (���Z�Ъ�Ūk�N-���t)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,mk,busy;
 
 if(!me) me=this_player();
 inn=me->query_int();
 mk=me->query_spell("god-fire");
 sk=mk/10+1;
 cost=(mk/3)+10+random(me->query("level"));
 
 if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target ) return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

        //�ˬd�O�_�i�H����
 if(!me->can_fight(target))
                return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
            return notify_fail("�A���k�O�����C\n");
 message_vision(HIG"\n$N����X�Q�A���ۻy�D�G�u�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC�v\n"NOR,me);
 busy=2;
	me->start_busy(busy); //�I�k�ʧ@�ɶ�
	me->receive_damage("mp",cost); //�I�k��MP
	me->set_temp("power_cast",1+mk/33);

	if(userp(me)) 
		call_out("delay",busy*2-1,target,me,mk);
	else 
		call_out("delay",busy*2-2,target,me,mk);
 return 1;
}


int delay(object target,object me,int mk)
{
int inn,sk,damage,shield,level;

 if(!me) return 0;                                      
 if(!target) return notify_fail("�ؼЮ����F�C\n");      
 if( environment(me) != environment(target) )           
          return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if( me->query_temp("power_cast") < 1) 
 {
  message_vision(
	HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 level=me->query("level");
 shield=target->query_shield();

    damage = mk+inn*3+level;
    damage = damage/2 + random(damage/2);
    if(userp(me))	damage=damage+(damage/4)-random(damage/8);
    damage = damage - shield/2 -random(shield/2);
    if(userp(target)) 	damage=damage-damage/5;
    if(damage<1)	damage=random(inn+mk/3);

 message_vision(
HIR"\n��M$N��W�P�K�ĤѡA���_�@�D�u���Z�u���v���N�V$n�I�I\n"NOR
,me , target);

if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)

	if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me );
       message_vision(HIC "$N�{�������@�D�u���Z�u���v����աI\n"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->qu
ery("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n");
       COMBAT_D->report_status(target);         //���target���A
	}
    else
        {
                message_vision(GRN"�u��$N�F�{����A�n���e�����}�@�D�u���Z�u���v���r�P��աC\n"NOR,target);
        }
 } else message_vision(GRN" �u���Z�u���v�r�P���N�V$N, �����G�S���y��$N���@���ˮ`�C\n"NOR,target);

 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(random(2+mk/25)==0) me->start_busy(1);
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 if(random(8)<1) me->add_busy(1);

//�G�s�o
if(me->query_spell("god-fire")>89 && random( inn ) > random( -(COMBAT_D->dodge_factor(target,"dodge")/2 )  ) )
	{
		call_out("delay2",2+random(5),target,me,mk);
	}

return 1;
}

int delay2(object target,object me,int mk)
{
 int inn,sk,damage,shield,level;
                                                        
if(!me) return 0;
if(!target) return notify_fail("�ؼЮ����F�C\n");
if( environment(me) != environment(target) )
          return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

sk=mk/20+random(mk/20)+1;
inn=me->query_int();
level=me->query("level");
shield=target->query_shield();
    damage = mk+inn*3+level;
    if(userp(me)) damage=damage+(damage/4)-random(damage/8);
	    damage = ( damage - shield/2 -random(shield/2) ) /2 + random(me->query_spell("god-fire"));
   if(userp(target)) damage=damage-damage/5;

message_vision(HIR"�b�����I�I$N���I��X�{�@���������s�A���˦ӥX�A���ĦV$n�I�I\n"NOR,me,target);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
   // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        target->receive_damage("hp", damage, me ); 
        message_vision(HIR"$N�G�s�@�n�A��Ө��߳Q���s�@�f�ҧ]���I�I"NOR,target);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
        COMBAT_D->report_status(target);         //���target���A
    }
    else
	{ message_vision(GRN"�u�����s�r�M���]����$N�A�����G�S���y��$N���@���ˮ`�C\n"NOR,target); }
 
if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
	 if(random(2+mk/25)==0) me->start_busy(1);
	 if(!target->is_fighting(me)) target->kill_ob(me);
	 if(!me->is_fighting(target)) me->kill_ob(target);
}
