// Skill of CLASS: killer
// killer-instict 殺手本能
// Write by -alickyuen@ds-
#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
    int skill;

    skill = me->query_skill("killer-instinct", 1);

    tell_object(me, HIR"你的殺手本性增強了......\n"NOR);
    me->add("evil", -1);
}
