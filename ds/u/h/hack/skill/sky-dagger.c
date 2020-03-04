#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N������A�u���a�����v�w�M�X�ۡA$w����Ӱ_�A�¦V$n���ӥh�C",
        "damage":                8,
        "dodge" :               10,
        "attact_type":  "bar",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�ϥX�u�����b��v�A���M����$n����A�⤤��$w�A�r�V$n��h�C",
        "damage":                15,
        "dodge":                -15,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�ϥX�@�ۡu���N�b�ѡv�A�a�_�b�ذ��A���M��$n�����ӤU�C",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N����@���A�@���u�븨�Q�ڡv�A�⤤$w��$n����ӥh�C",
        "damage":                 8,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�V��@�D�A�u���a�X���v�k��$w�浹����A���M�X�۪���$n����ʬ֥ަӥh�C",
        "damage":                 7,
        "dodge" :                20,
        "parry" :               -20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�ϥX�u�@�ۤG���v�A���зL�}�A����X�x�ӥk��X�P�A�X$n���j���ɡA�P���w��$n���A�ӥh�I",
        "damage":                15,
        "dodge" :                10,
        "parry" :               -20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N��ϡu���a�����v���$n���A���M�S�@���u�����ѻڡv�A$w�ѤU�ӤW��V$n�C",
        "damage":                17,
        "dodge" :                10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N���Ⱚ�|, �@�ۡu�j�P�i�͡v�⤤$w�¦V$n�����Y�F�L�h�C",
        "damage":                10,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�ϥX�u�N���L���v�A���M����$n���e�A����e�N�����դ޶}�ĤH�`�N�A���M�j�ܤ@�n�A$w����ӥh�C",
        "damage":                20,
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
        if(me->query_skill("dagger")<10) return notify_fail("�A���P����¦�����L�k�ϥΤѼS�P�k�C\n");
        if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΤѼS�P�k�C\n");

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
          if(me->query_skill("sky-dagger")>60)
          {
            if(me->query("ap")>50)
            {
             i=me->query_skill("sky-dagger");
             if(i>90) i+=10;
             if(random(i)>30)
             {
              damage = random(me->query_skill("sky-dagger"))*2+ random(me->query("str"))*3/2;
              damage = damage/2 + random(damage) + me->query_damage();
              damage -= random(target->query_armor());
              
             msg = HIW "\n$N���Ѩg�S�A���ۡu�ѱ������ĥդ�v�@�ۨg���V$n�A"+weapon->query("name")+"�Ʀ��L�v���P�V$n��h�C\n\n" NOR;
              msg += HIR "$n�]�{�פ��ΡA�ӳ�����A�����L�ƭ��@�ˡA�A�媽�y�A�ݨӨ��ˤ����C\n\n" NOR;
               
              damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
              target->receive_damage("hp",damage,me);
              COMBAT_D->report_status(target);
              me->receive_daemage("ap",30);
              target->start_busy(2);
              me->start_busy(3);
             }
             else {
     msg = HIW "\n$N���Ѩg�S�A���ۡu�ѱ������ĥդ�v�@�ۨg���V$n�A"+weapon->query("name")+"�Ʀ��L�v���P�V$n��h�C\n\n" NOR;
              msg += HIB "�u��$n�W�W�i�i���k�}$N�����ۡA�o�]�~���y��o�աC\n" NOR ;
              me->receive_daemage("ap",20);
              target->start_busy(2);
              me->start_busy(2);
             }
           if(!me->is_fighting(target)) me->kill_ob(target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           message_vision(msg, me, target);
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

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
