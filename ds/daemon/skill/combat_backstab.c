#include <ansi.h>
#define SKILL_NAME "�԰��I��"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
    int damage,sk,c;
    int cost;
    object weapon;
    if(!me) return 0;
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�n�b�԰����~��ϥ�!\n");
    if( me->query("class2") != "thief" ) return notify_fail("�n�i���p���~��ϥγ�I\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("��֬I�i"+SKILL_NAME+"?\n");
    if( !living(target) || target->is_corpse() )
        return notify_fail("�A�M�F��?!?�o���O�A�������աC\n");
    //        if( userp(me) && !wizardp(me) ) return notify_fail("A testing skills.\n");
    if((int)me->query("mp") < 75 || (int)me->query("ap") < 75 )
        return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
    if(!weapon=me->query_temp("weapon")) return notify_fail("�A�⤤�S���Z������I��C\n");
    if(!weapon->can_stab()) return notify_fail("�A�ҨϥΪ��Z�����A�X�ΨӭI��C\n");
    //	if(!me->can_fight(target))
    //		return me->can_fight(target);

    sk=me->query_skill("combat_backstab");
    cost = me->query("level")/2+sk/2;
    c=target->query_armor();
    message_vision("\n"HIW" �y�K���z $N"HIW"�N���@�n�����M�����F�ܼv�A�����X�{�b$n"HIW"������!!\n"NOR,me,target);
    me->receive_damage("mp", cost);
    me->receive_damage("ap", cost);
    me->add_busy(3);
    if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
    {
        message_vision("\n"HIW"$N���t���N�⤤��"+weapon->name()+HIW"��V$n"HIW"������A���O�Q$n"HIW"�@���ਭ�{�F�L�h!!\n"NOR,me,target);
        return 1;
    }
    else
    {
        damage = me->query_damage()*2+sk/2;
        damage = damage + random(damage/2)+(int)weapon->query("backstab_bonus");
        damage = damage - c/2 -random(c/2);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        message_vision("\n"HIW"$N���t���N�⤤��"+weapon->name()+HIW"��V$n"HIW"������A$n"HIW"�G�s�@�n�A"HIR"�A��q�ˤf���u��ӥX!!\n"NOR,me,target);
        target->receive_damage("hp", damage,me);
        COMBAT_D->report_status(target);
        if(wizardp(me) && me->query("env/debug")) tell_object(me,"["+me->name()+"�����԰��I�� damage: "+damage+"]\n");
        me->improve_skill("combat_backstab", 1+random(sk/2)+random(me->query("level")));
    }

    return 1;
}


