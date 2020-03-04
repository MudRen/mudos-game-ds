
//QC: Luky 1999.8.17
// ���s�K�� (dragon_fist)
// copy from dragonfist.c
// Tmr 2006/12/12
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�x�տ���g���A�@�ۡu�s�C�L���v�H�_�����������V$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "�x��",
        ]),

        ([
        "action": "$N�ϥX�u�s�ߤo�_�v�A���s�Ʀ������������k���V$n",
        "damage":                20,
        "dodge" :               -15,
        "parry" :               -10,
        "attact_type":  "bar",
            "damage_type":  "����",
        ]),

        ([
        "action": "$N���ηL�y�A�ѤU�ӤW�_���A�@�ۡu�s�}�ƻa�v������$n��$l���h",
        "damage":                20,
        "dodge" :                20,
        "attack":               -15,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N�����@�B�A�����F��p�N�A�b�b�Ť��ϥX�F�u�s�����ѡv�@�ۥ��V$n��$l",
        "damage":                20,
        "dodge" :                5,
        "parry" :                5,
        "attact_type":  "bar",
        "damage_type":  "�x��",
        ]),

        ([
        "action": "$N�@�ۡu���s�Ѥ��v�x�l�z�o�������l�A�w�O��$n��$l�����A�U",
        "damage":                20,
        "attack":                20,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N���x�B��A�u���s�{�@�v���ձN���⤧�O�D���V$n",
        "damage":                25,
        "dodge" :               -15,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N�������ˡA���ۡu�g�s�S�ѡv������l����k�x�W�A���ձ��V$n",
        "damage":                40,
        "dodge" :               -35,
        "parry" :               -35,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
});

int exert(object me, object target, string arg)
{
        object weapon;

        weapon=me->query_temp("weapon");
        if(weapon)
        {
                if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("�A�⤤�ҫ����Z���A���A�X�Φb���s�K���C\n");
        }
        if(arg=="off" )
        {
                if( me->query_skill_mapped("unarmed")!="dragon-fist")
                        return notify_fail("�A�èS���b�ϥΡu���s�K���v�C\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("�A����ϥί��s�K���F�C\n");
                return 1;
        }
  

        if( me->query_skill_mapped("unarmed") == "dragon-fist")
                        return notify_fail("�A�w�g�b�ϥΡu���s�K���v�F�C\n");
        if(me->query_skill("unarmed")<10) 
                return notify_fail("�A���{��i���ݭn10�šA�~��ϥί��s�K���C\n");
   if(me->query("ap")<20 || me->query("hp")<30) 
                return notify_fail("�A�����骬�p���}�A����ϥί��s�K���C\n");
        me->map_skill("unarmed", "dragon-fist");
        me->reset_action();
        message_vision(HIG "$N���X��ԤQ���κI�ߪk�A�I�i�X���s�K���C\n"NOR,me);
    me->receive_damage("ap",10);
        me->start_busy(2);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        return ob->query_str() + 30;
}

