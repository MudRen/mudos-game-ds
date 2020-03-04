/*
�� �ʴH�y(freeze-ball) - �H����(frost) �ޯ�

    �ʴH�y�O�H�������򥻦B���k�N�A�N�ĤH�|�g��
�Ů��t���Ũ�F�B�I���{�סA�y���ĤH�L�k�ۥѦ�
�ʤΦB��ˮ`�C

�򥻶ˮ`�� 5% ~ 30% �����O�C
�ޯ�C10�żW�[3%�ˮ`�O�A�@30%�A�m����35% ~ 60%�����O�C

�B��^�X�G��1�^�A�C33�żW�[1�^�A�����@4�^�C

Last update: Tmr 2006/11/13
*/

#include <ansi.h>

#define SKILL_NAME "freeze-ball"
#define MIN_DAMAGE 5
#define MAX_DAMAGE 30

inherit SSERVER;
inherit SKILL;

int cast_delay(object target,object me);

int cast(object me, object target)
{
    int skill, cost;

    skill = me->query_spell(SKILL_NAME);
    cost = 10 + skill/5;

    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");
    if ( me == target )
        return notify_fail("�A�L�k��ۤw�I�k�C\n");
    if ( me->query("mp") < cost )
        return notify_fail("�A���k�O�����A�L�k�I�k�C\n");
    if ( !me->is_fighting(target) )
        return notify_fail("�A�èS���M���b�԰����C\n");
    if ( !me->can_fight(target))
        return me->can_fight(target);


    message_vision(HBK"$N�I�i�X�ʴH�y�k�N�A���x�ߤ����Ů�v�����E�b�@�_�C\n"NOR, me, target);
    me->receive_damage("mp", cost);
    me->start_busy(1);
call_out( (:cast_delay, target, me:), 1);
    return 1;
}

int getDamageWeight(object me)
{
    int bonus;
    // �C10�ť[3%
    bonus = (me->query_spell(SKILL_NAME)/10) * 3;
    return (MIN_DAMAGE + bonus) + random(MAX_DAMAGE - MIN_DAMAGE);

}

int getShield(object target)
{
    return target->query_shield()/2 - random(target->query_shield()/2);
}

int getDamage(object me, object target)
{
    int damage;
    damage = me->query_damage() * getDamageWeight(me)/100 - getShield(target);
    if ( damage < 1 )
        damage = 1;
    // �W�[�����ˮ`���v�T
    return COMBAT_D->Merits_damage(me,target,damage,"wit");
}

void show_damage(object me, object target, int damage)
{
    if ( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
    if ( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if (wizardp(me) && me->query("env/debug"))
        tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n");
}

int getBusyTime(object me)
{
    return 1 + (me->query_spell(SKILL_NAME)/33); // �C33�ť[1 busy
}
int cast_delay(object target, object me)
{
    int probit, damage;
    int hit;
    string msg;

    if ( !me )
        return 0;
    if ( !target )
        return notify_fail("�ؼЮ����F�C\n");
    if ( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

    message_vision("$N�⤤��"HIW"�y"HIC"�ʴH�y"HIW"�z"NOR"�W�դw���A�H�Y��$n"NOR"����V���h�I�I\n"NOR,me,target);

    probit += me->query_spell(SKILL_NAME) + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_int());

    hit = probit > random(100);
    msg = HIB"$N"HIB"�Q�ʴH�y���ӥ��ۡA�S�p�m���B���I�I"NOR;
    if ( !hit ) {
        if ( me->query_condition("frost_dust")
                && me->query_skill("pure-energy")/3 > random(100)  // 33%
                && 50 > random(100)   // 50%
           ) {
            // dust_clean �G���A�R��
            hit = 1;
            msg = HIB"$N"HIB"�Q�Ы��b�ɪ��ʴH�y���ӥ��ۡA�S�p�m���B���I�I"NOR;
        }
    }

    if ( hit > 0 )  {
        damage = getDamage(me, target);
        if (damage<1) damage = 1;
        target->receive_damage("hp", damage, me );
        message_vision(msg,target);
        show_damage(me, target, damage);
        message_vision("\n", me, target);
        COMBAT_D->report_status(target);         //���target���A

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()) );
        target->start_busy( getBusyTime(me) );
    }
    else {
        message_vision(GRN"���O$N"GRN"���}�F�o�������C\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/3) );
    }

    if ( !target->is_fighting(me) )
        target->kill_ob(me);
    if ( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


