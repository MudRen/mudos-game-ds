// ���u�C�k quanzhen-sword.c
// Tmr 2006/10/28

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
                       ([
                        "action":"$N�N�a���~�A�@��"GRN"�u����جh�v"NOR"�A$w�������ʡA�۰_�@���C���A��$n����",
                            "damage":                15,
                            "dodge" :                10,
                            "parry" :                -8,
                            "attact_type":  "bar",  
                            "damage_type":  "���",
                        ]),

                       ([
                        "action":"$N�Ϥ@��"HIY"�u�^�ߤT�|�v"NOR"�A���ΦV�W�ư_�A�⤤$w�����ۥX�T�I�H���g�V$n$l",
                            "damage":                10,
                            "dodge":                 -5,
                            "parry" :                14,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                        "action":"$N���Τ@��A�r�M�@��"HIG"�u�\\�������v"NOR"�A�R�X���ѼC�v�A���۫l���V$n��$l���h",
                            "damage":                17,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action":"$N���Ѫ����A�����ƵM�Ӱ_�A�b�b�Ť����l�@�ۡA�@��"HIM"�u�g�q�h���v"NOR"�g����a���V$n",
                            "damage":                13,
                            "dodge" :                20,
                            "parry" :                -10,
                            "attact_type":  "bar",
                            "damage_type":  "�C��",
                        ]),

                       ([
                        "action":"$N�V�e�ڥh�@�j�B�A�ϥX"HIB"�u�����O�s�v"NOR"�A�⤤$w�R���@�ӥ��y�A���Y�b�p���V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                                "action":"$N�B�O�@��$w�A�@��"HIM"�u���ศ��v"NOR"�A$w�ۥX�I�I�C��A�ƵM��V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                        "action":"$N�⤤$w�׫��a�ѡA�a�_�V�l�A�@��"YEL"�u���z�_�v"NOR"�A$w�p�^��g�V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                                "action":"$N�j�ܤ@�n�A�@��"HIW"�u�խi�g�ѡv"NOR"�A$w�{�q�빺�X�@�D�j�꩷�A�V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                "action":"$N���ΦV�W�ư_�A��M�@�ਭ�A�Y�U�}�W�A�ⴤ$w�A�@��"HIW"�u���Y�L�n�v"NOR"�A�L�n�L���a��V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                "action":"$N�⤤$w�@�ݡA�@��"HIR"�u�ӯ}�U�t�v"NOR"�A$w�G�Xģ�����~�A�ĤO���V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
        "action":"$N���M���ΰ����D�_�A�ϥX"HIC"�u����ѲP�v"NOR"�A$w�ۥX���Ѫ�ä�A���p�p�^�g�V$n��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="quanzhen-sword")
            return notify_fail("�A�èS���ϥΥ��u�C�k�C\n");
        me->map_skill("sword");
        me->reset_action();
        write("�ޯ�[���u�C�k]�w�����C\n");
        return 1;
    }

    if(!weapon)
        return notify_fail("�ϥΥ��u�C�k�����⤤�n���C�C\n");
    if(weapon->query("skill_type")!="sword")
        return notify_fail("�ϥΥ��u�C�k�����⤤�n���C�C\n");
    if(me->query_skill("sword")<10)
        return notify_fail("�A���C�k��¦�����L�k�ϥΥ��u�C�k�C\n");
    if(me->query("ap") < 10 || me->query("hp") < 10)
        return notify_fail("�A�����骬�p�L�k�ϥΥ��u�C�k�C\n");
    if( me->query_skill_mapped("sword")=="quanzhen-sword")
        return notify_fail("�A�w�g�b�ϥΥ��u�C�k�C\n");

    me->map_skill("sword", "godsword");
    me->reset_action();
    message_vision(CYN" $N�f�w�C�Z�A�}�l�I�i�y���u�C�k�z�C\n"NOR,me);
    me->receive_damage("ap",6); //luky
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

