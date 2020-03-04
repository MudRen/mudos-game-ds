#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 	string msg;
        int damage,c,force;
	if ( !force ) force = me->query("force_factor");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�y�嶧�C�g �B��i�p�z�u���԰��������ϥΡC\n");
	if( me->query("hp") < 200 || me->query("mp") < 160 )
                return notify_fail("�A����O�ΥͩR�O�w�g�����F.\n");
        if( me->query_skill("thundersword") < 50 )
		return notify_fail("�A���ʹp���C�ۦ��٤������, �L�k�ϥX�y�嶧�C�g �B��i�p�z.\n");
    if( me->query_skill("force") < 40 )
		return notify_fail("�A�����\�����`�p, �򥻨Ϥ��X�y�嶧�C�g �B��i�p�z.\n");
	msg = HIC "$N�ϥX�ʹp���C�����ޡM�y�嶧�C�g �B��i�p�z\n���ѷ��a���¤O��V$n!!�M";
	c = target->query_temp("apply/armor");
        if ( c > 150 ) c = 150;
	damage = (me->query_skill("thundersword")*4)+((((300+random(300))*me->query("mp"))/me->query("max_mp")));
	damage = (damage + ((damage * force)/100)) - (c*2);
        if ( damage < 500 ) damage = 350 + random(150);
	me->start_busy(1);
        me->add("mp",-65);
        me->add("hp",-50);
    if( 22 + random(me->query_skill("thundersword")) > 43 ) {
		msg += "���G$p�Q$P�����A���T\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage);
	} else {
		msg += "�i�O�Q$p���{�F�}�h�C\n" NOR;
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target,1);
	return 1;
}
