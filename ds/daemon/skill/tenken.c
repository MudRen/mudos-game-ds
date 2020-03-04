// tenken.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
                       ([      "action":               "$N�ĤOģ�_�M�k���ĥX�@�O�j�l��"HIG"�u�@�s�}�v"NOR"�M���V$n��$l�T\n",
                               "damage":                30,
                               "dodge":                -30,
                               "parry":                -30,
                               //                "force":                260,
                               "damage_type":  "�޶�"
                        ]),
                       ([      "action":               "$N���a�@���ਭ����M"HIC"�u���P�e���}�v"NOR"���G$n$l�T\n",
                               "damage":                30,
                               "dodge":                -30,
                               "parry":                -30,
                               //                "force":                240,
                               "damage_type":  "���"
                        ]),
                       ([      "action":               "$N���l�L�סM�H�Y��X�@�B�M�ֻL�p�{�q��a���X"HIB"�u�ۼv�}�v"NOR"�M�ƨg�aŧ��$n�T\n",
                               "damage":                40,
                               "dodge":                -40,
                               "parry":                -40,
                               //                "force":                220,
                               "damage_type":  "���"
                        ]),
                       ([      "action":               "$N�j��:"HIW"�u���ڤ@�O���㪺�K���T�v"NOR"�M�r������$n��$lݴ�h�T\n",
                               "damage":                20,
                               "dodge":                -20,
                               "parry":                -20,
                               //                "force":                240,
                               "damage_type":  "���"
                        ]),
                       ([      "action":               "$N�ƨg���X"HIM"�u�ٯP���v"NOR"�M�u���L�Ʋr�P�����v��������$n�T\n",
                               "damage":                40,
                               "dodge":                -40,
                               "parry":                -40,
                               //                "force":                250,
                               "damage_type":  "�޶�"
                        ]),
                       ([      "action":               "$N�j�q:"HIR"�u�a���j�����v"NOR"�M����D�_�M�p�Ⱦj���r�~�뼳�V$n�T\n",
                               "damage":                50,
                               "dodge":                -50,
                               "parry":                -50,
                               //                "force":                280,
                               "damage_type":  "�L��"
                        ]),
                       ([      "action":               "$N�k���˪Ť@���M�@�ۨg�r��"HIY"�u��׮��v"NOR"�I�S�ӥX�M�b�V$n�T\n",
                               "damage":                30,
                               "dodge":                -30,
                               "parry":                -30,
                               //                "force":                300,
                               "damage_type":  "�_��"
                        ]),
                   });

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("���K�氫�ެO���ʥ|�Ϫ���N�A�n�{��~��m�ߡC\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"|| usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("hp") < 50 )
        return notify_fail("�A����O(�֢�)�t�����F�A�𮧤@�U�A�m�a�C\n");
    if( (int)me->query("sp") < 10 )
        return notify_fail("�A�������q(���)�֯ӺɤF�A�𮧤@�U�A�m�a�C\n");
    me->receive_damage("hp", 50);
    me->add("sp", -10);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;

    if( random(damage_bonus/2) > victim->query_str() ) {
        victim->receive_wound("hp", (damage_bonus - 100) / 2 );
        switch(random(3)) {
        case 0: return "�Ať��u�ذաv�@�n���T�M�����O���H���n���T\n";
        case 1: return "$N�l�O�@�R�M$n��$l�o�X�u�ءv�a�@�n�z�T�T\n";
        case 2: return "�uť��$n��$l�u�ءv�a�@�n ...\n";
        }
    }
}
