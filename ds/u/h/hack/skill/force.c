// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }


void skill_improved(object me)
{
	int s;

	s = me->query_skill("force", 1);
	if( s%10==9 && (int)me->query("con") < s/4) {
		tell_object(me, HIW "�ѩ�A�����\\�׷Ҧ����M�A�����ﵽ�F�C\n" NOR);
		me->add("con", 2);
	}
}