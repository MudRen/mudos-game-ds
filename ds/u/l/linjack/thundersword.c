#include <ansi.h>;
inherit SKILL;

mapping *action = ({
(["action": "$N�ϥX�@���u���E�{�@���v,��$w���ѦӤU,��$n��$l�A�h",
"damage":               120,
"dodge" :               -30,
                "damage_type":  "�A��"
        ]),
(["action":"$N�����, �@�ۡu���P���ܡv,$w�����Ʀ��|�D�C��,\n
�|�D�C�𪽮g�V$n��$l",
                "damage":    50,
                "dodge" :    50,
                "attack":    50,
                "damage_type":  "���"
        ]),
(["action":"$N�ϥX�u�@�C�ʪe�s�v,�⤤����$w, �o�X�j�j�C��\n�g�V$n��$l",
                "damage": 100,
                "dodge": 10,
]),
(["action":"$N�R�ƼC��, �@���u�F�p�u�_�ѡv,$w���C�b�W�UŸ��,\n�Φ��@���q��
�ʦ�$n���h��,�L�ƪ��C���V$n���U�j�n��",
"damage": 160,
"attack": -40,
"dodge" : -20,
"damage_type":  "���"
        ]),
(["action":"$N�B�X�u�g�F�U�����v�@�ۨg���V$n,$w�Ʀ��L�v���C�V$n��h",
"damage":  80,
"dodge":   50,
"damage_type":  "���"
	]),
(["action":"$N�ϥX���ۡu���@�C�g�p�_�v,$w��ĭ�t���������V$n��h",
"damage": 200,
"dodge":  -50,
"attack": -50,
"damage_type":  "���"
	]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
	return notify_fail("�A�S�����C�A�p��m�ʹp���C�H\n");

	if( (int)me->query("max_mp") < 500 )
	return notify_fail("�A�����O�����M�S����k�m�ʹp���C�C\n"); 
       return 1;
}
int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry" || usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
if( (int)me->query("dex")<50)
if( (int)me->query("int")<50)
return notify_fail("�A����O����,���A�X�ǳo���C�k�C\n");
        me->add("mp",-50);
        write("�A���۩Ҿǽm�F�@�M�C�ۡC\n");
        return 1;
}

string perform_action_file(string action)
{
	return "/daemon/skill1/thundersword/" + action;
}
