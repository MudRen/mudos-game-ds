/*
�� ���p�b (fall-thunder) - �H����(frost) �ޯ�
 
    ���p�b�O�H�������򥻹p�k�k�N�A�H�G�y�Y�X�@�D
�a�j�P�q�l���b�ڡA�y���ĤH�ˮ`�C�ϥθ��p�b������
�H�A���i��o�͡u�q���v�{���A�y���󰪪��ˮ`�C
 
���p�b�ˮ`�G30% ~ 70% �����O
�ޯ�C5�żW�[3%�ˮ`�A�@60%�A�i�F�� 90% ~ 130% �����O
 
�q�����v�G�ޯ൥��40�ɬ�10%�A�C3�żW�[2%�A�̰����v��50%�C
�q���ˮ`�G���q�b�ˮ`�� 80%
 
�� �T�n�ʻ�b
 
    �ޯ൥��60�ŮɡA�i�@���Y�X�T�D���p�b�C
    �C24��i�ϥΤ@���A�C�@�Isou�i���2���ݮɶ��A�̦h����12��C
 
Last update: Tmr 2006/11/27

11.27 �[�W�u�ͦ��šv
        
*/

#include <ansi.h>

#define SKILL_NAME "fall-thunder"
#define MIN_DAMAGE 30
#define MAX_DAMAGE 70

inherit SSERVER;
inherit SKILL;

int cast_delay(object target,object me);

void clear_flag(object me)
{
    if( !objectp(me) )
        return;
    me->delete_temp("FROST_FALL_THUNDER");
    tell_object(me, "�A�w�g��_�F�T�n�ʻ�b���k�N�C\n");
}

int cast(object me, object target, string act)
{
    int skill, cost;

    skill = me->query_spell(SKILL_NAME);
    cost = 20 + skill/4;

    if( me == target )
        return notify_fail("�A�L�k��ۤw�I�k�C\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");
    if( me->query("mp") < cost )
        return notify_fail("�A���k�O�����A�L�k�I�k�C\n");
    if( !me->is_fighting(target) )
        return notify_fail("�A�èS���M���b�԰����C\n");
    if( !me->can_fight(target))
        return me->can_fight(target);
    if( me==target )
        return notify_fail("�A�Q�n��ۤw�I�k�H\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");


    me->start_busy(2);
    if( skill >= 60
            && !me->query_temp("FROST_FALL_THUNDER")
            && me->query("mp") > cost*3 )
    {
        int delay;
        // �T�n�ʻ�b
        message_vision(HBK"$N�I�i"HIM"�T�n�ʻ�b"HBK"�k�N�A�⤤���_��X�����q�T�A�@�n��@�n��j�n�C\n"NOR, me, target);
        me->receive_damage("mp", cost*3);
        me->set_temp("FROST_FALL_THUNDER", 1);
call_out( (:cast_delay, target, me:), 2);
        delay = 24 - me->query_sou()*2;
        if(delay <12) delay = 12;
call_out( (:clear_flag, me:), delay);
    }
    else
    {
        message_vision(HBK"$N�I�i���p�b�k�N�A�⤤���_��X�����q�T�C\n"NOR, me, target);
        me->receive_damage("mp", cost);
call_out( (:cast_delay, target, me:), 2);
    }
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
        damage = me->query_damage() + me->query_int();
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
    if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
    if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n");
}

// �q�����v�G�ޯ൥��40�ɬ�10%�A�C3�żW�[2%�A�̰����v��50%�C
void do_attack(object me, object target)
{
    int  sk_lv, chance, damage;
    sk_lv = me->query_spell(SKILL_NAME);
    chance = 10 + (sk_lv-40)/3*2;
    if( chance < random(100) )
        return; // nothing happen
    damage = getDamage(me, target) * 8/10; // 80%
    if(damage < 1) damage = 1;
    message_vision(RED"�@�}"HIB"���T"NOR RED"�q$N�餺�ǥX�ӡA�y�����Y�����ˮ`�I�I"NOR,target);
    show_damage(me, target, damage);
    message_vision("\n", me, target);
}

int cast_delay(object target, object me)
{
    int probit, damage;
    int sk_lv, i, times, hit;
    object symbol;

    if( !me )
        return 0;
    if( !target )
        return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

    sk_lv = me->query_spell(SKILL_NAME);
    probit = sk_lv + me->query_int();
    probit -= random(target->query_skill("dodge")+target->query_dex());
    if(me->query_temp("FROST_FALL_THUNDER") == 1 ) {
        times = 3; // �T�n�ʻ�b
        me->set_temp("FROST_FALL_THUNDER", 2);
    }
    else times = 1;
    hit =  probit > random(100) || target->is_busy() ;

   if( !hit ) {
                if( me->query_condition("frost_dust") 
                        && me->query_skill("pure-energy")/3 > random(100)  // 33%
                        && 50 > random(100)   // 50%
        ) {
                // dust_clean �G���A�R��
                hit = 1;
                message_vision(HIB"$N�Ы��b�ɡA���W�o�X�C�I�Ӿ��[�����������n�I�I"NOR,me);
        }
        } 


    if( hit )
    {
        for(i = 0;i<times;i++) {
            damage = getDamage(me, target);
            if( objectp(symbol=present("__LIFE_DEATH_SYMBOL_", me)) ) {
                // add harvest by tmr 2007/03/03
                if( me->query_condition("frost_harvest") && me->query_skill("pure-energy")/2 > random(100) ) {
                    message_vision(HIC"$N�����H�H�H���ƶh�A�@�D�Y�����L���L�νb�ڦ�ۤ����B�A�a�۴����q�T�A�������N�S�J$n"HIC"�餺�I�I"NOR,me, target);
                } else {
                    symbol->add_amount(-1);    // ��֥ͦ���
                    message_vision(HIC"�@�D�Y�����L���L�νb�ڦ�ۤ����B�A�a�۴����q�T�A�������N�S�J$N"HIC"�餺�I�I"NOR,target);
                }
            } else {
                message_vision(HIC"�@�D�Y�����L���L�νb�ڱa�۴����q�T�A�������N�S�J$N"HIC"�餺�I�I"NOR,target);
            }
            target->receive_damage("hp", damage, me );
            show_damage(me, target, damage);
            message_vision("\n", me, target);
            // �q��
            if(sk_lv > 40)
                do_attack(me, target);

            COMBAT_D->report_status(target);         //���target���A
        }

        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()) );
    }
    else
    {
        message_vision(GRN"���O����Ƥ]�S���o��...\n"NOR,target);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()/3) );
    }

    if( !target->is_fighting(me) )
        target->kill_ob(me);
    if( !me->is_fighting(target) )
        me->kill_ob(target);

    return 1;
}


