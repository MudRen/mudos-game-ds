// relieve.c	解救技能	Shengsan@DS
#include <ansi.h>
inherit SKILL;

void skill_improved(object me)
{
	int lv;
	lv = me->query("level");
	if( random(100)%9 == 1 )
	{
		me->add("evil",-random(lv));
		tell_object(me, HIY"\n由於你努力的救人脫離險境！你的個性態度變好了一些。\n"NOR);
	}
	return;
}
