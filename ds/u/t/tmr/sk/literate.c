#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s;

        s = me->query_skill("literate", 1);
          if( s%30==0 && random(5)==0) {
                      tell_object(me, HIY "由於你的勤學苦讀﹐你的悟性提高了。\n" NOR);
                        me->add("addition/int", 1);
        }

}


