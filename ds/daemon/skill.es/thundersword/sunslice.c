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
		return notify_fail("『驚陽劍狂 冰日虹雷』只能對戰鬥中的對手使用。\n");
	if( me->query("hp") < 200 || me->query("mp") < 160 )
                return notify_fail("你的體力或生命力已經不夠了.\n");
        if( me->query_skill("thundersword") < 50 )
		return notify_fail("你的封雷絕劍招式還不夠精熟, 無法使出『驚陽劍狂 冰日虹雷』.\n");
    if( me->query_skill("force") < 40 )
		return notify_fail("你的內功不夠深厚, 跟本使不出『驚陽劍狂 冰日虹雷』.\n");
	msg = HIC "$N使出封雷絕劍必殺技﹐『驚陽劍狂 冰日虹雷』\n毀天滅地的威力攻向$n!!﹐";
	c = target->query_temp("apply/armor");
        if ( c > 150 ) c = 150;
	damage = (me->query_skill("thundersword")*4)+((((300+random(300))*me->query("mp"))/me->query("max_mp")));
	damage = (damage + ((damage * force)/100)) - (c*2);
        if ( damage < 500 ) damage = 350 + random(150);
	me->start_busy(1);
        me->add("mp",-65);
        me->add("hp",-50);
    if( 22 + random(me->query_skill("thundersword")) > 43 ) {
		msg += "結果$p被$P重重劈中﹗\n" NOR;
		target->start_busy(1);
                target->add("hp",-damage);
	} else {
		msg += "可是被$p給閃了開去。\n" NOR;
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target,1);
	return 1;
}
