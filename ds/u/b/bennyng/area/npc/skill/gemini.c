#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
        ([
        "action": "$N���ɦV�e, ���x�|�_, �@�ۡu���g�]�Ӯ��v���V$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "���",
        ]),
        ([
        "action": "$N����|�_�V$n�o�X�@�ۡu�������Ŷ��v",
        "damage":                15,
        "dodge" :               -10,
        "attact_type":  "bar",
            "damage_type":  "�W��",
        ]),
        ([
        "action": "$N����X,�@�ۡu�]�ӱY�����v�V\$n�����g��_��",
        "damage":                30,
        "attack":                30,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
        ([
        "action": "$N���O�X��, �@�ۡu�Ьӯ��P���v������ਭ���V$n",
        "damage":                35,
        "attack":                35,
        "attact_type":  "bar",
        "damage_type":  "'����",
        ]),
        ([
        "action": "$N��W�@�{, �@�O�u���t���v���V$n",
        "damage":                10,
        "attack":                35,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "'���",
        ]),
});
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
