#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
    int force,ninning,heal;

    force=me->query_skill("force",2);
    ninning=me->query_skill("ninning-force",2);
    heal=(force+ninning)/2;

    if(arg=="heal" )
    {
        if(me->query("ap") < heal/3 )
            return notify_fail("你目前的情況，不能使用九陰神農。\n");
        if(me->query("hp") == me->query("max_hp"))
            return notify_fail("你並沒有受傷 . . .\n");
        message_vision(HIB "$N以真氣打通奇筋八脈，隨著氣孔噴出，在$N的背後形成一神農氏之像。\n" NOR,me);
        me->receive_damage("ap",heal/3);

        if (me->is_fighting() ) me->receive_heal("hp",heal*1/2 );
        else me->receive_heal("hp",heal);

        me->start_busy(1);
        me->improve_skill("ninning-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
    }

    return notify_fail("九陰真經有神農補血之術等多項技能。\n");
}


int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me)
{
    int b,c;
    b = me->query_skill("ninning-force",1);
    c = me->query("skill/ninning-force");

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me,HIR "你用心鑽研九陰真經使得力量提高了！\n" NOR );
            me->add("addition/str", 1);
        }
        else
        {
            tell_object(me,HIC "你用心鑽研九陰真經使得體質提高了！\n" NOR );
            me->add("addition/con", 1);
        }

        me->set("skill/ninning-force",b);
    }
    me->save();
    return;
}

