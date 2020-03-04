#include <ansi.h>
#define SKILL_NAME "�����g��"
inherit SKILL;
inherit SSERVER;


int exert(object me, object target,string dir)
{
    object weapon,arrow;
    string msg;
    int sk,skk;
    seteuid(getuid());

    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("��֬I�i"+SKILL_NAME+"?\n");
    if((int)me->query("ap") < 30 || (int)me->query("mp") < 30 )
        return notify_fail("�A�ثe�����骬�p�L�k�I�i�o��@�P���ʧ@�T\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if( !weapon=me->query_temp("weapon") ) return notify_fail("�A�S���Z���p��I�i"+SKILL_NAME+"�H\n");
    if( weapon->query("skill_type")=="bow")
    {
        if( !arrow=present("arrow 2", me ) ) return notify_fail(" �A���b�����C\n");
    }
    else
    {
        if(!weapon->query("can_shoot"))
            return notify_fail("�A�ثe�ϥΪ��Z���L�k�g���C\n");
        if(weapon->query_temp("loaded") < 2 )
            return notify_fail("�ϥ�"+SKILL_NAME+"�ܤ֭n��o�u�ġC\n");
    }
    message_vision(HIC"\n$N���t�����_"+weapon->name()+HIC", �I�i"+SKILL_NAME+"�C\n\n"+NOR,me,target);
    if(weapon->do_shoot(me,target))
    {
        me->receive_damage("ap",15);
        me->receive_damage("mp",10);
    }
    if(weapon->do_shoot(me,target))
    {
        me->receive_damage("ap",15);
        me->receive_damage("mp",10);
    }
    sk=me->query_skill("doubleshoot");
    skk=sk/2+random(sk);
    me->improve_skill("doubleshoot",1+random(me->query_int()/5));
    if(skk < 50 ) me->add_busy(1);
    return 1;
}


