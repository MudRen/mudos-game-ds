//eeman, �k�N�n�[ delay �A�����D��??
// �٦������ޯण�O�Φb�A���԰���H���W��, �Τ���SSERVER

#include <ansi.h>
inherit SKILL;
int cast(object me, object target)
{
	if( !target ) target = me;

	if( !target
	||	!target->is_character()
	||	target->is_corpse())
		return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");
	if( !living (target) )
     		return notify_fail(HIY"�o���O�ͪ���I\n"NOR);

	if((int)me->query("mp") < 5 )
		return notify_fail("�A���k�O�����T\n");

	 if( me->query_temp("cast") )
	    return notify_fail("�A���b�I�k�C\n");
	    
	me->add("mp", -5);
	me->set_temp("cast","heal");
	me->start_busy(2);
	message_vision("\n[1;35m$N�N�����b$n������, �f����������G��..[0m\n\n",me);
	call_out("do_heal",2,me,target);
}

int do_heal(object me, object target)
{
  string msg;
  
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("cast");
    return notify_fail("��H���G�����F�A���I�k�d��..\n");
  }
	if( random(me->query("max_mp")) < 30 )
	{
		write("�A���ѤF�C\n");
		return 1;
	}

	msg = HIM "$N������@�X�M$n���Ǻ����E�_�@�ε����T\n\n" NOR;

	msg += "$n���W���ж˺�����_�F�C\n";

	message_vision(msg, me, target);
	me->improve_skill("berserk",1+random(me->query_int()/10));
	target->receive_heal("hp", 50);

	me->delete_temp("cast");
	return 1;
}

