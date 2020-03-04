/*
�ѹp�T�� (thunder-doom) - �H����(frost) �i���ޯ�
Tmr 2008/02/02
*/

#include <ansi.h>

#define SKILL_NAME "thunder-doom"
#define MIN_DAMAGE 60
#define MAX_DAMAGE 100

inherit SSERVER;
inherit SKILL;

int cast_delay(object me);

int cast(object me, object target)
{
    int skill, cost;
    object *targets;
    targets = me->query_enemy();

    skill = me->query_spell(SKILL_NAME);
    cost = 30 + skill/3;

        if( !me->is_fighting() )
        return notify_fail("�A�èS���b�԰����C\n");
    if ( sizeof(targets) < 0 )
        return notify_fail("�A�S���i�H�������ﹳ�C\n");
    if ( me->query("mp") < cost )
        return notify_fail("�A���k�O�����A�L�k�I�k�C\n");

    if (userp(me))
        me->start_busy(1);
    else
        me->start_busy(2);
    message_vision(HBK"$N���G�I�i"HIC"�y�ѹp�T�ơz"HBK"�A�l���p�B���O�A�u���ѪůQ���K�G�A�p�n�F�F�C\n"NOR, me, target);
    me->receive_damage("mp", cost);
call_out( (:cast_delay, me:), 2);

    return 1;
}

int getDamageWeight(object me)
{
    int bonus;
    // �C5�ť[3%
    bonus = (me->query_spell(SKILL_NAME)/5) * 3;
    return (MIN_DAMAGE + bonus) + random(MAX_DAMAGE - MIN_DAMAGE);
}

int getShield(object target)
{
    return target->query_shield() - random(target->query_shield()/2);
}

int getDamage(object me, object target)
{
        int damage;
        object symbol;
        // �[�W int
        damage = me->query_damage() + me->query_int()*2;
        if ( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) )
                damage += symbol->query("power")*3/2;
        damage = damage * getDamageWeight(me)/100;
        damage -= getShield(target);
        if ( damage < 1 )
        damage = 1;
        // �W�[�����ˮ`���v�T
        return COMBAT_D->Merits_damage(me, target, damage,"wit");
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

// �q�����v�G�ޯ൥��40�ɬ�10%�A�C3�żW�[3%�A�̰����v��70%�C
void do_attack(object me, object target)
{
    int  sk_lv, chance, damage;
    sk_lv = me->query_spell(SKILL_NAME);
    chance = 10 + (sk_lv-40)/3*3;
    if ( chance < random(100) )
        return; // nothing happen
    damage = getDamage(me, target) * 6/10; // 60%
    if (damage < 1) damage = 1;
    message_vision(RED"�@�}"HIB"���T"NOR RED"�q$N�餺�ǥX�ӡA�y�����Y�����ˮ`�I�I"NOR,target);
        show_damage(me, target, damage);
    target->receive_damage("hp", damage, me );
    message_vision("\n", me, target);
}

int doAttack(object me, object target)
{
    int probit, damage;
    int sk_lv, hit;
    object symbol;

    sk_lv = me->query_spell(SKILL_NAME);
    probit = sk_lv + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_dex());
    hit =  probit > random(100) || target->is_busy() ;

    if ( !hit ) {
        if ( me->query_condition("frost_dust")
                && me->query_skill("pure-energy")/3 > random(100)  // 33%
                && 50 > random(100)   // 50%
           ) {
            // dust_clean �G���A�R��
            hit = 1;
            message_vision(HIB"$N�Ы��b�ɡA���W�o�X�C�I�Ӿ��[�����������n�I�I"NOR,me);
        }
    }


    if ( hit )
    {
        damage = getDamage(me, target);
        if ( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) ) {
            // add harvest by tmr 2007/03/03
            if ( me->query_condition("frost_harvest") && me->query_skill("pure-energy")/2 > random(100) ) {
                message_vision(HIC"$N�����H�H�H���ƶh�A�@�D"BLU"�ѹp"HIC"��ۤ����B«�X�A�F���n�T���������N���W$n"HIC"�I�I"NOR,me, target);
            } else {
                symbol->add_amount(-1);    // ��֥ͦ���
                message_vision(HIC"�@�D"BLU"�ѹp"HIC"��ۤ����B«�X�A�F���n�T���������N���W$N"HIC"�I�I"NOR,target);
            }
        } else {
            message_vision(HIC"�@�D"BLU"�ѹp"HIC"«�X�A�F���n�T���������N���W$N"HIC"�I�I"NOR,target);
        }
        target->receive_damage("hp", damage, me );
        show_damage(me, target, damage);
        message_vision("\n", me, target);
        // �q��
          if (sk_lv >= 40)
            do_attack(me, target);

        COMBAT_D->report_status(target);         //���target���A

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/4) );
    }
    else
    {
        message_vision(GRN"���O����Ƥ]�S���o��...\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/12) );
    }

    if ( !target->is_fighting(me) )
        target->kill_ob(me);
    if ( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


int cast_delay(object me)
{
    object *targets;

    int i, sz, ct;
    if ( !me )
        return 0;
    targets = me->query_enemy();
    sz = sizeof(targets);
    if (sz<0)
        return notify_fail("�A�S������i�H�������ﹳ�C\n");
    // �̦h�|�ӼĤH
    for (i=0, ct =0 ;i<sz && ct < 4; i++) {
        if ( !targets[i] ) continue;
        if ( environment(me) != environment(targets[i]) ) continue;

        doAttack(me, targets[i]);
        ct++;
    }

    return 1;
}

