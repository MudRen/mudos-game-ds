// �������X
// tmr 2006/11/16

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
    int s,c;

    s = me->query_skill("strong-body", 1);
    c = me->query("skill/strong-body");//luky
    if( s%19 == 18 && s > c)
    {
        tell_object(me, HIY "�ѩ�A�������X�A���w�y�A�s�z�w�K�A�A����责���F�C\n" NOR);
        me->add("addition/con", 1);
        me->set("skill/strong-body",s);
    }

}


