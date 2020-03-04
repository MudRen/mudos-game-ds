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
            return notify_fail("�A�ثe�����p�A����ϥΤE�����A�C\n");
        if(me->query("hp") == me->query("max_hp"))
            return notify_fail("�A�èS������ . . .\n");
        message_vision(HIB "$N�H�u�𥴳q�_���K�ߡA�H�ۮ�ռQ�X�A�b$N���I��Φ��@���A�󤧹��C\n" NOR,me);
        me->receive_damage("ap",heal/3);

        if (me->is_fighting() ) me->receive_heal("hp",heal*1/2 );
        else me->receive_heal("hp",heal);

        me->start_busy(1);
        me->improve_skill("ninning-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
    }

    return notify_fail("�E���u�g�����A�ɦ大�N���h���ޯ�C\n");
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
            tell_object(me,HIR "�A�Τ��p��E���u�g�ϱo�O�q�����F�I\n" NOR );
            me->add("addition/str", 1);
        }
        else
        {
            tell_object(me,HIC "�A�Τ��p��E���u�g�ϱo��责���F�I\n" NOR );
            me->add("addition/con", 1);
        }

        me->set("skill/ninning-force",b);
    }
    me->save();
    return;
}

