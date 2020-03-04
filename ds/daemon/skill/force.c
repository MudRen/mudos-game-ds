// force.c

#include <ansi.h>

inherit SKILL;
string type() { return "basic"; }

int valid_learn(object me) { return 1; }


void skill_improved(object me)
{
    int s,c;

    s = me->query_skill("force", 1);
    c = me->query("skill/force");
    if(s==0) return;

    return; // 由strong-body取代，所以不需要加con了 -Tmr 2006/11/22
    if( s%20 == 0 && s > c)
    {
        tell_object(me, HIW "由於你的內功\修煉有成﹐你的體質改善了。\n" NOR);
        me->add("addition/con", 1);
        me->set("skill/force",s);
    }
}

