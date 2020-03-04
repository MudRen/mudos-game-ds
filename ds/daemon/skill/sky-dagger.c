#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
                       ([
                            "action": "$N������A�u"HIW+BLK"���a����"NOR"�v�w�M�X�ۡA$w����Ӱ_�A�¦V$n���ӥh�C",
                            "damage":               12,
                            "dodge" :               10,
                            "attact_type":  "bar",  // �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIY"�����b��"NOR"�v�A���M����$n����A�⤤��$w�A�r�V$n��h�C",
                            "damage":                14,
                            "dodge":                -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�@�ۡu"HIW+BLK"�𭸩Ѥ�"NOR"�v�A�a�_�b�ذ��A���M��$n�����ӤU�C",
                            "damage":                16,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N����@���A�@���u�븨�Q�ڡv�A�⤤$w��$n����ӥh�C",
                            "damage":                18,
                            "dodge" :               -10,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�V��@�D�A�u"HIY"���a�X��"NOR"�v�k��$w�浹����A���M�X�۪���$n����ʬ֥ަӥh�C",
                            "damage":                20,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u�@�ۤG���v�A���зL�}�A����X�x�ӥk��X�P�A�X$n���j���ɡA�P���w��$n���A�ӥh�I",
                            "damage":                22,
                            "dodge" :                10,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N��ϡu"HIW+BLK"���a����"NOR"�v���$n���A���M�S�@���u"HIC"�����ѻ�"NOR"�v�A$w�ѤU�ӤW��V$n�C",
                            "damage":                24,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���Ⱚ�|, �@�ۡu"HIC"�j�P�i��"NOR"�v�⤤$w�¦V$n�����Y�F�L�h�C",
                            "damage":                26,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIR"�N���L��"NOR"�v�A���M����$n���e�A����e�N�����դ޶}�ĤH�`�N�A���M�j�ܤ@�n�A$w����ӥh�C",
                            "damage":                28,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    int c,damage,sk,i;
    string msg;
    object weapon;
    weapon=me->query_temp("weapon");
    if(!weapon) return notify_fail("�ϥΤѼS�P�k�����⤤�n���P���C\n");
    if(weapon->query("skill_type")!="dagger") return notify_fail("�ϥΤѼS�P�k�����⤤�n���P���C\n");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dagger")!="sky-dagger")
            return notify_fail("�A�èS���ϥΤѼS�P�k�C\n");
        me->map_skill("dagger");
        me->reset_action();
        write("�ޯ�[�ѼS�P�k]�w�����C\n");
        return 1;
    }
    if(me->query_skill("dagger")<20) return notify_fail("�A���P����¦�����L�k�ϥΤѼS�P�k�C\n");
    if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("�A�����骬�p�L�k�ϥΤѼS�P�k�C\n");

    //�ĤG��exert
    if(me->query_skill_mapped("dagger")=="sky-dagger")
    {
        if( !target ) target = offensive_target(me);
        if(!target)   return notify_fail("�A���b�ϥΡu�ѼS�P�k�v�C\n");
        if(!target) return notify_fail("��⤣���F�C\n");
        if(!me) return notify_fail("��⤣���F�C\n");
        if(!me->is_fighting()) return notify_fail("�԰�����F�C\n");
        if( environment(me) != environment(target) ) return notify_fail("�䤣����@�C\n");
        // �����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target))
            return me->can_fight(target);
        c = target->query_armor();
        if(me->query_skill("sky-dagger")>40)
        {
            if(me->query("ap")>250)
            {
                i=me->query_skill("sky-dagger");
                if(i>90) i+=10;
                msg = HIW "\n$N���Ѩg�S�A���ۡu"CYN"�ѱ������ĥդ�"HIW"�v�@�ۨg���V$n"HIW"�A$N�⤤��"+weapon->query("name")+HIW"�Ʀ��L�v���P�V$n��h�C\n\n" NOR;
                if(random(i)>30)
                {
                    damage = random(me->query_skill("sky-dagger"))*2+ random(me->query("str"))*3/2;
                    damage = damage/2 + random(damage) + me->query_damage();
                    damage -= random(target->query_armor());
                    if (damage > 160) damage = 160;

                    msg += HIR"$n"HIR"�]�{�פ��ΡA�ӳ�����A�����L�ƭ��@�ˡA�A�媽�y�A�ݨӨ��ˤ����C\n\n" NOR;

                    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                    target->receive_damage("hp",damage,me);
                    me->receive_daemage("ap",100);
                    target->start_busy(1);
                    me->start_busy(3);
                }
                else {

                    msg += HIB "�u��$n"HIB"�W�W�i�i���k�}$N�����ۡA�o�]�~���y��o�աC\n" NOR ;
                    me->receive_daemage("ap",20);
                    target->start_busy(2);
                    me->start_busy(2);
                }
                if(!me->is_fighting(target)) me->kill_ob(target);
                if(!target->is_fighting(me)) target->kill_ob(me);
                message_vision(msg, me, target);
                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                if(wizardp(me) && me->query("env/debug"))
                    tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n");

                COMBAT_D->report_status(target);
                return 1;
            }
            else {
                tell_object(me,"�A����O�L�k�t���o�ѼS�P�k���Ͼ_���O�C\n");
            }
        }
        else {
            tell_object(me,"�A���ѼS�P�k������ԡA�L�k�ϥίS�\\�C\n");
        }
    }
    if(me->query_skill_mapped("dagger")=="sky-dagger") return notify_fail("�A���b�ϥΤѼS�P�k�C\n");
if(!me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("�A���۪��ʧ@�٨S�����C\n");
    me->map_skill("dagger", "sky-dagger");
    me->reset_action();
    message_vision("\n"HIW" $N�ⴤ"+weapon->name()+"��ݫe�A�}�e�u���N�ߪK�v, �}�l�I�i�y�ѼS�P�k�z�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("dagger");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="dagger")
    {
        me->map_skill("dagger");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("dagger")!="sky-dagger")
    {
        return;
    }
    if(me->query("ap")<7)
    {
        me->map_skill("dagger");
        me->reset_action();
        message_vision("\n"HIW"$N����O�����L�k�~��ϥΤѼS�P�k, �u�n��Τ@��ۦ��C\n"NOR,me);
        return ;
    }
    if( me->is_fighting() ) me->receive_damage("ap",6);
me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10);
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int valid_learn(object me)    { return 1; }
int practice_skill(object me) { return 1; }

