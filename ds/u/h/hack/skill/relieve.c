// relieve.c	�ѱϧޯ�	Shengsan@DS
#include <ansi.h>
inherit SKILL;

void skill_improved(object me)
{
	int lv;
	lv = me->query("level");
	if( random(100)%9 == 1 )
	{
		me->add("evil",-random(lv));
		tell_object(me, HIY"\n�ѩ�A�V�O���ϤH�����I�ҡI�A���өʺA���ܦn�F�@�ǡC\n"NOR);
	}
	return;
}
