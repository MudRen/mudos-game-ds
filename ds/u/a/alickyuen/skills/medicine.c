// 醫學(medicine)：醫生公會
#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s,c;

        s = me->query_skill("medicine", 1);
 	c = me->query("skill/medicine");
	if( s%19 == 18 && s > c)
	{
                      tell_object(me, HIY "由於你的勤學苦讀，你的悟性提高了。\n" NOR);
                        me->add("addition/int", 1);
                        me->set("skill/medicine",s);
        }

}


