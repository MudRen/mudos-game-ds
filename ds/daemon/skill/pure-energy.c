// ���ߪk (pure-energy) - �H�����i�����\
//by Tmr 2007/03/03

#include <ansi.h>
inherit SKILL;

int heal(object me);
int threahing(object me);
int harvest(object me);
int dust(object me);

int exert(object me,object target, string arg)
{
    if(arg =="heal" )
        return heal(me);
    if(arg=="threshing")
        return threahing(me);
    if(arg=="harvest")
        return harvest(me);
    if(arg=="dust_clean")
        return dust(me);

    return notify_fail("���ߪk���\\��аѦ� help pure-energy�C\n");

}

int heal(object me) {
    int force,sk,heal;

    force = me->query_skill("force", 2);
    sk = me->query_skill("pure-energy", 2);

    if(me->query("hp") >= me->query("max_hp") ) return notify_fail("�A�����d���p�}�n�A���ݭn���ˡC\n");
    if(me->query("ap") < heal/2 ) return notify_fail("�A�����l�����A�L�k���ˡC\n");
    if (me->is_fighting() ) return notify_fail("�A�����۾԰��A�S�������ˡC\n");

    heal = (force+sk)/2;
    message_vision( "$N�I�a�@�n�A�q�L�̽w�w�R�X�X���N��A���W���˶դ]�C�C��_�F�C\n" ,me);
    me->receive_damage("ap",heal/2);
    me->receive_heal("hp",heal/2);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );

    me->start_busy(1);
    return 1;
}


int threahing(object me) {
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 30 ) return notify_fail("�A�����ߪk�����m�A�L�k�I�i�u���U���ɡv�C \n");
    if ( me->query_skill("force") < 30 ) return notify_fail("�A�����\\�ߪk�����m�A�L�k�I�i�u���U���ɡv�C \n");
    if ( me->query("ap") < 60 ) return notify_fail("�A�����l�����A�L�k�I�i�u���U���ɡv�C\n");
    
        if ( me->query_condition("frost_threshing") ) 
                return notify_fail("�A�w�g�b�I�i�u���U���ɡv�C\n");
        if ( me->query_temp("pure-energy/threshing") ) 
                return notify_fail("�A�w�g�b�I�i�u���U���ɡv�C\n");

    message_vision(HIG "$N�ϥX���U���ɤ��k�A�⤤�{�p�����U���A��������A�����n���T�����C \n" NOR,me);

    me->receive_damage("ap",60);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
    me->set_temp("pure-energy/threshing", sk/2 );
    me->add_temp("apply/damage", sk/2 );
    me->start_busy(2);
        me->apply_condition("frost_threshing", 10 + sk/5);
    return 1;
}

int harvest(object me)
{
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 50 ) return notify_fail("�A�����ߪk�����m�A�L�k�I�i�u�E���@���v�C \n");
    if ( me->query_skill("force") < 50 ) return notify_fail("�A�����\\�ߪk�����m�A�L�k�I�i�u�E���@���v�C \n");
    if ( me->query("ap") < 80 ) return notify_fail("�A�����l�����A�L�k�I�i�u�E���@���v�C\n");
    if ( me->query("mp") < 80 ) return notify_fail("�A���]�O�����A�L�k�I�i�u�E���@���v�C\n");
    if ( me->query_condition("frost_harvest") ) return notify_fail("�A�w�g�b�I�i�u�E���@���v�C\n");

    message_vision(HIC "$N�B�ΤE���@�����k�A�����H�H�H���ƶh�A�[�[�����C \n" NOR,me);

    me->receive_damage("ap",80);
    me->receive_damage("mp",80);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
        me->apply_condition("frost_harvest", 10 + sk/7);
    me->start_busy(2);
    return 1;
}

int dust(object me)
{
    int sk;
    sk = me->query_skill("pure-energy");
    if ( sk < 70 ) return notify_fail("�A�����ߪk�����m�A�L�k�I�i�u�Ы��b�ɡv�C \n");
    if ( me->query_skill("force") < 70 ) return notify_fail("�A�����\\�ߪk�����m�A�L�k�I�i�u�Ы��b�ɡv�C \n");
    if ( me->query("ap") < 120 ) return notify_fail("�A�����l�����A�L�k�I�i�u�Ы��b�ɡv�C\n");
    if ( me->query("mp") < 120 ) return notify_fail("�A���]�O�����A�L�k�I�i�u�Ы��b�ɡv�C\n");
    if ( me->query_condition("frost_dust") ) return notify_fail("�A�w�g�b�I�i�u�Ы��b�ɡv�C\n");

    message_vision(HIB "$N�B�_�Ы��b�ɤ��k�A���اC�I�Ӿ��[�����������n�A���_�q���W�o�X�C \n" NOR,me);

    me->receive_damage("ap",120);
    me->receive_damage("mp",120);
    me->improve_skill("force",1+ random(me->query_int()) );
    me->improve_skill("pure-energy",1+ random(me->query_int()/2) );
        me->apply_condition("frost_dust", 10 + sk/9);
    me->start_busy(2);
    return 1;
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}


