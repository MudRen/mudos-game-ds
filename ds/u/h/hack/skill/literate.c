#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s,c;

        s = me->query_skill("literate", 1);
 	c = me->query("skill/literate");//luky
	if( s%19 == 18 && s > c)
	{
                      tell_object(me, HIY "�ѩ�A���ԾǭWŪ�M�A�����ʴ����F�C\n" NOR);
                        me->add("addition/int", 1);
                        me->set("skill/literate",s);
        }

}


