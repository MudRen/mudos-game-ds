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
		return notify_fail("�y��v�߲��y �p�}�z�u���԰��������ϥΡC\n");
	if( me->query("hp") < 250 || me->query("mp") < 200 )
                return notify_fail("�A����O�ΥͩR�O�w�g�����F.\n");
	msg = HIC "$N�h��@�B�A���ܤ@�n�A�y��v�߲��y �p�}�z���n�ϥX�M\n$N��W�o�X�j���~���V$n!!�M";
	damage = me->query_skill("moonthunder") + me->query("str") * 3 +me->query("dex") * 2 + me->query("mp");
	me->start_busy(3);
        me->add("mp",-140);
        me->add("hp",-100);
    if( 22 + random(me->query_skill("thundersword")) > 44 ) {
		msg += "���G$p�Q$P���n�����T\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage+random(400));
	} else {
		msg += "�b�d�v�@�v���ڡA$p�{�F�}�h�C\n" NOR;
	}
	message_vision(msg, me, target);
    COMBAT_D->report_status(target,1);

	return 1;
}
