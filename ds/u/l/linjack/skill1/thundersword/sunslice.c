#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 	string msg;
        int damage;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�y�g�p�C ����z�u���԰��������ϥΡC\n");
	if( me->query("hp") < 200 || me->query("mp") < 160 )
                return notify_fail("�A����O�ΥͩR�O�w�g�����F.\n");
	msg = HIC "$N�ϥX�ʹp���C�����ޡy�g�p�C ����z�M\n���ѷ��a���¤O��V$n!!�M";
	damage = me->query_skill("thundersword") + me->query("str") * 4 + me->query("mp");
	me->start_busy(3);
        me->add("mp",-100);
        me->add("hp",-80);
    if( 22 + random(me->query_skill("thundersword")) > 44 ) {
		msg += "���G$p�Q$P�����A���T\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage+random(400));
	} else {
		msg += "�i�O�Q$p���{�F�}�h�C\n" NOR;
	}
	message_vision(msg, me, target);
    COMBAT_D->report_status(target,1);

	return 1;
}
