#include <ansi.h>
inherit SKILL;
mapping *action = ({
 ([      "action":               "$N�w�w�����V$n�A�A�����Ω������k�A�O$n�ݤ��M�,
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "���",
        ]),
 ([      "action":               "$N���u�@���A�ϥX�C�ˮ���"HIW"�@"RED"�ߨ방"NO,
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "���",
        ]),
 ([      "action":               "$N�k�u�@���A���ä@�����X�A�I�i"HIC"�h"HIY"��",
                "dodge":                -50,
                "parry":                -50,
                "force":                100,
                "damage_type":  "���",
        ]),
 ([      "action":               "$N�f�B�u��ܤ�W�ֶ��T�J�g�A��j�Ӫ��������l�,
                "dodge":                -50,
                "parry":                -50,
                "force":                120,
                "damage_type":  "����",
        ]),
});
int valid_enable(string usage) { return usage=="unarmed"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

