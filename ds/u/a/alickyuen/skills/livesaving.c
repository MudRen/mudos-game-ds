// ��ϧޥ�(livesaving)  
// �~����� 

#include <ansi.h>
inherit SKILL;
int exert(object me, object target)
{
        if(!objectp(present("first aid box",me) ) ) 
                return notify_fail("�A�o�������@�u��C\n");
	if( !target ) target = me;
	if( !living (target) )
     		return notify_fail("�o���O�ͪ���I\n");
	if((int)me->query("ap") < 10 )
		return notify_fail("�A�����l�I�Ƥ����T\n");
	 if( me->query_temp("ex_sav") )
	    return notify_fail("�A���b�I�k�C\n");
	me->add("ap", -10);
	me->set_temp("ex_sav"); 
	me->start_busy(2);
	message_vision("\n $N���X���@�u�����$n�]�϶ˤf..\n\n",me, target);
	call_out("do_heal",2,me,target);
return 1;
}

int do_heal(object me, object target)
{
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("ex_sav");
    return notify_fail("��H���G���b�o�̡C\n");
  }
	message_vision("$n���W���ˤf�_�X�F�C\n",me, target);
// �������S�g��
me->improve_skill("livesaving",20+random(10));
	target->receive_curing("head", random(me->query_skill("livesaving")/10));
	target->receive_curing("body", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_leg", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_leg", random(me->query_skill("livesaving")/10));
	me->delete_temp("ex_sav");
	return 1;
}

