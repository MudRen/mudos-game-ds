#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�e�t�����R�⤤��$w�ϥX�u�T�v�r�Z�A�L�ƪ��C��Φ��@�D�C���N$N��ӤH\n��¶�b�@���C������",
        "damage":                5,
        "dodge":                 -5,
        "parry" :               30,
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�ɳܤ@�n�A�����M��$n���}��A�ϥX�u�}�v�r�Z�C�C��V$n���}��A\n�۩۪���$n���n�`",
        "damage":                20,
        "dodge":                -15,
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�C�դ@�ܡA�I�i�@���u�ۡv�r�Z�A��ӤH�H���֪��t�׶i�氪�t���j��\n�A�P�ɩ�$n��$l�g�٦ӥh",
        "damage":                15,
        "dodge" :                -5,
        "parry" :                10,
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�ɧq�@�n�A�@�D�ܪŤ��ϥX�u�١v�r�Z�A\n�j�j���C��t�X�L�񪺯}�a�O���F$n������",
        "damage":                25,
        "dodge" :                -15,
        "parry" :                -15,
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�H���֪����k����$n�����ǡA�ϥX�@���u���v�r�Z�A\n�ѤU�ӤW�A�٦V$n���U�E",
        "damage":                15,
        "dodge" :                5,
        "damage_type":  "�C��",
        ]),

      
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="nallurace_sword")
                        return notify_fail("�A�èS���ϥΨ��|�p���M�h�y�C�k�C\n");
                me->map_skill("sword");
                me->reset_action();
                write("�ޯ�y���|�p���M�h�y�C�k�z�����C\n");
                return 1;
        }
        if(!weapon) return notify_fail("�A���{���A�i�H�Ť�ϥμC�k�a�C\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("�ϥμC�k�⤤�n����C�A�o�O�򥻱`�ѧa�C\n");
        if(me->query_skill("sword")<10) return notify_fail("���U�I�A����¦�C�N����t�A�ڥ��b���d�o�M�C�k�C\n");
        if(me->query_skill_mapped("sword")=="nallurace_sword")
                return notify_fail("�A���b�ϥΨ��|�p���M�h�y�C�k�C\n");
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΨ��|�p���M�h�y�C�k�C\n");
        me->map_skill("sword", "nallurace_sword");
        me->reset_action();
        message_vision("\n"HIC" $N���|�⤤��"+weapon->name()+"�A�V���|�p�����ꪺ��V��ӼC§�A�}�l�I�i�y���|�p���M�h�y�C�k�z�C\n"NOR,me,target);
        me->add("mp", -4);
        me->start_busy(1);
        call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(weapon->query("skill_type")!="sword")
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(me->query_skill_mapped("sword")!="nallurace_sword")
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N��O���~�A�L�k�~��I�i���|�p���M�h�y�C�k�A�t�׳v���C�F�U�ӡC\n"NOR,me);
                remove_call_out("delay");
                return ;
        }
        me->add("mp",-4);
        call_out("delay",5,me);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
