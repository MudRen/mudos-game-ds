//�y�H�ޯ�G��(psychical)

#include <ansi.h>
inherit SKILL;

void delay(object me);
void armor(object me,int effect);
void power_up(object me,int effect);

int exert(object me,object target, string arg)
{
    int lv;
    lv=me->query_skill("psychical",1);

    if( arg=="off" && me->query_temp("is_busy/psychical") )
    {
        message_vision("$N�����F�u�I�v���צ�C\n",me);
        me->delete_temp("is_busy/psychical");
        return 1;
    }
    if(arg=="off")
        return notify_fail("�A�èS���׽m�u���v�C\n");

    if(!arg || arg=="exercise")
    {
        if(me->query_temp("is_busy/psychical") )
            return notify_fail("�A�w�g�b���u�I�v���צ�C\n");
        if(me->query("hp") < 5 || me->query("ap") < 5 )
            return notify_fail("�A�ثe�����骬�p���n�A�L�k�צ�u���v�C\n");
        if(me->is_fighting() )
            return notify_fail("�A�����ۥ��[�A�S�Ű��u�I�v���צ�C\n");

        message_vision(HIW "$N�L�����F�U�ӡA�}�l�u�I�v���צ�C\n" NOR,me);
        me->receive_damage("hp",3);
        me->receive_damage("ap",3);
        me->set_temp("is_busy/psychical","�A���b���u�I�v���צ�A�Ȯɤ��ಾ�ʡC");
        me->start_busy(2);
me->skill_active( "psychical",(: call_other, __FILE__, "delay", me:), 2);
        return 1;
    }

    if(arg=="engird")
    {
        int psy,limit;
        psy=me->query_temp("psychical_power");

        if( lv < 30)
            return notify_fail("�A�u���v����O�����A�L�k�ϥΡu��v�C\n");
        if(me->query("ap") < 100 || me->query("hp") < 100)
            return notify_fail("�A�{�b�����骬�A���n�A�L�k�ϥΡu��v�C\n");
        message_vision(GRN"$N�ϥΡu��v�յ��x�s���O�C\n" NOR,me);
        switch(lv/10)
        {
        case 3:
        case 4:
        case 5: limit=lv*5;     break;
        case 6:
        case 7:
        case 8: limit=lv*8;     break;
        default: limit=lv*10;
        }
        me->start_busy(2);
        me->improve_skill("psychical",1+random(2) );
        me->receive_damage("hp",lv);
        me->receive_damage("ap",lv);
        if( lv+psy < limit ) {
            me->add_temp("psychical_power",lv);
            return notify_fail("�Aı�o�餺�����O���G�W�[�F�C\n");
        }
        else return notify_fail("�A�èS��ı�o���P�C\n");
    }
    return notify_fail("�u���v�ثe���I(exercise)�M��(engird)���\\��C\n");
}

void delay(object me)
{
    int inn,conn,exp;
    inn=me->query_int();
    conn=me->query_con();
    exp=(inn*3+conn*2)/6+random(3);

    if ( !me
            ||   !me->query_temp("is_busy/psychical")
            ||    me->is_fighting() )       return;

    if(me->query("hp") < 5 || me->query("ap") < 5 )
    {
        message_vision("$N�����F�u�I�v���צ�C\n",me);
        me->delete_temp("is_busy/bagi_force");
        me->map_skill("bagi_force");
        return;
    }
    me->improve_skill("psychical",exp );
    me->receive_damage("hp",3);
    me->receive_damage("ap",3);
me->skill_active( "psychical",(: call_other, __FILE__, "delay", me:), 3);
    return;
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
    int a;
    a = me->query_skill("psychical", 1);
    if( a % 5==0 && random(a*2) > random(a*3) )
    {
        if(random(2)==1) {
            tell_object(me,HIY "�A���O�q�����F�I\n" NOR );
            me->add("addition/str", 1);
        }
        else {
            tell_object(me,HIY "�A����责���F�I\n" NOR );
            me->add("addition/con", 1);
        }
    }
    return;
}
