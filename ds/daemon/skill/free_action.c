// free_action.c
#include <ansi.h>
inherit SKILL;

void skill_improved(object me)
{
    int s,c;
    s = me->query_skill("free_action", 1);
    c = me->query("skill/free_action");
    if( s%25 == 24 && s > c)
    {
        tell_object(me, HIY "�A���ӱ����@�F�C\n" NOR);
        me->add("addition/dex", 1);
        me->set("skill/free_action",s);
    }
}
