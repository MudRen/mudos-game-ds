// 1.�԰��T���L����, �ӥB�T���᭱��'�C'���ݭn, �Э��s��z�@�U�T��
// 2. if �M else �ԭz�бƦC���. { �M } ��m�n�۹�����


#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�B�l���u�A�@�ۡu "HIG" �@��ʤs�e "NOR" �v�⤤$w�H�p�^�U�v���մ�$n�r�A�ӥh�C",
        "damage":             15,
        "dodge" :               10,
        "attact_type":  "bar",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�@�n�M�S�A�u "HIG" �������s¶ "NOR"�v$w�@�ݡA����¶��$n����Ӱ_�A��M$w�Ʃ۪���$n�۩I�ӥh�C",
        "damage":               17,

        "dodge":                12,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N����@�ϡA�u "HIG"�@���ٳ��� "NOR"�v�A�f���g�g�����A���ݪ�$n�����f�b�A�Z��$N���M���Τ@�{�A�@�P�ױױ��V$n�C",
        "damage":                16,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N���M����j���A�u "HIG" ����¾_�� "NOR" �v�A�|�P�շ�����A�@�P���H���p���l���V$n�A����$n�L�k�{���C",
        "damage":               20,
        "dodge" :               -20,
        "parry" :                 -10,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

([
        "action": "$N�y�⩿�{�g������A�u "HIG" �D��E�d�� "NOR" �v�@���g�٦ӥX �A�@�D����H�}�ˤ��ձ٦V$n�C",
        "damage":               19,
        "dodge" :                20,
        "parry" :                -20,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�",
        ]),

        ([
        "action": "$N���M���Y��è�A�u "HIG" �Ƥ߯}��� "NOR"�v�A�ƩۺC�P�H���i�઺���٦V$n�I",
        "damage":               15,
        "dodge" :                10,
        "parry" :                -20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�l�z�P�I�A�u "HIG" �g�R�P�_�� "NOR"�v�A �N$w�ϱo�K���z���A����$n�ļ��ӥh! ",
        "damage":               17,
        "dodge" :                10,
        "parry" :                 10,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N��B���l�Ϥ⤤$w�o�X���šA�u"HIG" �Ʈ�F�p�K "NOR"�v��$n����ӥh! �C",
        "damage":               18,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�N��",
        ]),

        ([
        "action": "$N�ϥX�u "HIG" �e���p�v�H "NOR" �v�A�l�z�����A�C��$n����A�򴤤⤤$w��$n�H�K�������C",
        "damage":               20,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

       ([

        "action": "$N�ϥX�u "HIG" ���ͨg���� "NOR" �v�A�l�z���u�A�B�_�����Ϩ��Ǳ��_�g���A�Ϧa�W���F���ۡA�X���}���A$w�V$n����ӥh�C",
        "damage":               19,
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
        if(!weapon) return notify_fail("�ϥΡy�Ĥѯ��P�z�����⤤�n���P���C\n");
        if(weapon->query("skill_type")!="dagger") return notify_fail("�ϥΡy�Ĥѯ��P�z�⤤�����n���P���C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("dagger")!="sigh_dagger")
                        return notify_fail("�A�èS���b�B��y�Ĥѯ��P�z�C\n");
                me->map_skill("dagger");
		me->reset_action();
                write("�A�f��y�Ĥѯ��P�z�߳Z�A�פ�F�y�Ĥѯ��P�z���B��C\n");
                return 1;
        }
        if(me->query_skill("dagger")<50||me->query_skill("sky-dagger")<60) return notify_fail("�A���P����¦�����L�k�ϥΡy�Ĥѯ��P�z�C\n");
                                        //..sky-dagger�O?
        if(me->query("ap")<60|| me->query("hp")<60) return notify_fail("�A�����骬�p�L�k�ϥΡy�Ĥѯ��P�z�C\n");

        //�ĤG��exert
        if(me->query_skill_mapped("dagger")=="sigh_dagger")
        {
          if( !target ) target = offensive_target(me);
          if(!target)   return notify_fail("�A���b�B��Ĥѯ��P�߳Z�C\n");
    
      // �����ʪ��n�S�O�`�N�n�[�U�����.
           if(!me->can_fight(target))
                return me->can_fight(target);
             c = target->query_armor();
          if(me->query_skill("sigh_dagger")>40)
          {
            if(me->query("ap")>60)
            {
             i=me->query_skill("sigh_dagger");
             if(i>90) i+=10;
		if(random(i)>random(50))
             {
              damage = random(me->query_skill("sigh_dagger"))*3+ random(me->query_int())*6/5;
              damage = damage/2 + random(damage);
              damage=damage-c/2-random(c);
 msg = HIW "\n$N���{�j������A�ݯ}�@���@���Z�~�A�y�Ѧa�@�z�z���M�j�{�����A"+weapon->query("name")+"�Ƭ��������P�V�|�P�g�A !!\n\n" NOR;
              msg += HIR "$n�@�n�G�s�A�����ɼƮ��J���������A�����L�ƭӨ`�ˡA�J�`�B�j�A�ݨӤ����]�ѥb���R�C\n\n" NOR;
               
              damage = COMBAT_D->Merits_damage(me,target,damage,"sou");
              target->receive_damage("hp",damage,me);
              COMBAT_D->report_status(target);
              me->receive_daemage("ap",20);
              target->start_busy(2);
              me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
             }
             else {
     msg = HIW "\n$N���{�j������A�ݯ}�@���@���Z�~�A�y�Ѧa�@�z�z���M�j�������A"+weapon->query("name")+"�Ƭ��������P�V�|�P�g�A !!\n\n" NOR;
              msg += HIB "�u��$n�O��߯��A�ɥ��O�P�����ܿšA���P�����P�y�A ���׹L�������T�C\n" NOR ;
              me->receive_daemage("ap",70);
           target->start_busy(2);
           me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
             }
           if(!me->is_fighting(target)) me->kill_ob(target);
           if(!target->is_fighting(me)) target->kill_ob(me);
           message_vision(msg, me, target);
           return 1;
            }
            else {
             tell_object(me,"�A����O�L�k�t���o�Ĥѯ��P�����j���ӡC\n");
            }
          }
          else {
            tell_object(me,"�A���y�Ĥѯ��P�z������ԡA�L�k�ϥΡy�Ѧa�@�z�z\�C\n");
          }
        }
        if(me->query_skill_mapped("dagger")=="sigh_dagger") return notify_fail("�A���b�ϥΡy�Ĥѯ��P�z�C\n");
        me->map_skill("dagger", "sigh_dagger");
        me->reset_action();
        message_vision("\n"HIW" $N�j�B�@��A����⤤�P���A�Q��Q���A�B�_�y�Ĥѯ��P�z���򥻤߳Z !! \n"NOR,me);
        me->receive_damage("ap",20); 
        me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
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
        if(me->query_skill_mapped("dagger")!="sigh_dagger")
        {
         return;
        }
        if(me->query("ap")<20)
        {
                me->map_skill("dagger");
                me->reset_action();
                message_vision("\n"HIW"$N���������áA�L�k�b�B��y�Ĥѯ��P�z�߳Z�C\n"NOR,me);
                return ;
        }
        if( me->is_fighting() ) me->receive_damage("ap",20);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
        }

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
