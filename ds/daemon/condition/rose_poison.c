// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    return 1;
	me->receive_wound("sen", 20);
	me->receive_damage("kee", 10);
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "�A����" HIR "�������r" HIG "�o�@�F�T\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
