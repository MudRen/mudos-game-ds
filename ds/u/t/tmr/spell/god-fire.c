//god-fire ���Z�u�� (���Z�Ъ�Ūk�N-���t)

#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target)
{
 int inn,sk,cost,lev;
 int lv,mk,lck;
 string who,name;
 
 if(!me) me=this_player();
 inn=me->query_int();
 lev=me->query("level");
 mk=me->query_spell("god-fire");
 sk=mk/10+1;

 if ( !me->is_fighting())
    return notify_fail("�u���Z�u���v�u���԰��ɤ~��ϥΡC\n");

 if ( !target ) target = offensive_target(me);
 if ( !target||!objectp(target = present(target, environment(me)))||target==me )
 	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");
 if(	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("�����k�N�u���ͪ��ϥΡC\n");
	}

	if(userp(me) && userp(target))
	{
	  if(me->query("level") < 5 ) return notify_fail("�A�ثe�����Ť��i�H�������a�T\n");
	  if(target->query("level") < 5 ) return notify_fail("�A���i�H�����p���C���Ū����a�T\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("�A���i�H�������Ŭۮt�Ӧh�����a�T\n");
	}
 if( (int)me->query("mp") <  cost )
	    return notify_fail("�A���k�O�����C\n");
 message_vision(HIG"\n$N����X�Q�A���ۻy�D�G�u�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC�v\n"NOR,me);
  me->start_busy(2);
  call_out("delay",3,target,me,mk);
  return 1;
}

int delay(object target,object me,int mk)
{
 int tlv,inn,lv,sk,i,damage,cost;
							
 if(!me) return 0;					
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 sk=mk/20+random(mk/20)+1;
 cost=(mk/5)+10;
 inn=me->query_int();
 lv=me->query("level");
 message_vision(HIR"\n��M$N��W�P�K�Ĥ�,�����q��ް_�@�D�u���Z�u���v�I�I\n\n"NOR,me);

 tlv=target->query("level");

 if( lv + random(inn) + inn > tlv+ random(inn) )
 {
    message_vision(HIG"\n$N�q���@�n�u���v�A�H�Y���_��W�u�����N�V$n�I�I\n\n"NOR,me,target);
    damage=( inn +random(mk) );
    damage -= target->query_sheild();
    damage -= target->query_skill("dodge")/10;

    me->receive_damage("mp",cost);

    if ( damage > 0)
    {
       message_vision(HIC"�u��$N�{�������@�D�u���Z�u���v����աA�Q�N�o�ֶ}�׺�I\n"NOR,target);
       target->receive_damage("hp", damage, me ); 
       target->start_busy(2);
    }
    else
	{
       message_vision(GRN"�u��$N�F�{����A�n���e�����}�@�D�u���Z�u���v���r�P��աC\n"NOR,target);
	}
 }


 if( inn>random(20) )
 {
         me->improve_spell("god-fire",inn+random(20));
 }
	 if(!target->is_fighting(me)) target->kill_ob(me);
	 if(!me->is_fighting(target)) me->kill_ob(target);
	 return 1;
}
