// unarmed.c

#include <ansi.h>
string type() { return "basic"; }

inherit SKILL;
void skill_improved(object me)
{
    int b,c;
    b = me->query_skill("unarmed",1);
    c = me->query("skill/unarmed");//luky

    if( b == 72 && b > c)
    {
        tell_object(me, HIW "�ѩ�A�Խm�Z���M�A���M�O�����F�C\n" NOR);
        me->add("addition/str", 1);
        me->set("skill/unarmed",b);
    }
    me->save();
}
