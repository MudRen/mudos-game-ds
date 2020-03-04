// snowwhip.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"�H���_��",
		"action":		"$N�Ϥ@�ۡu�H���_���v�M�⤤$w�ݱo�����V$n��$l�s����@",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"���"
	]),
	([	"name":			"���ѭ���",
		"action":		"$N���Τ@��M�@�ۡu���ѭ����v$w�ۥX�����@�v�M�����aŧ�V$n��$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"���"
	]),
	([	"name":			"���ὡ��",
		"action":		"$N�O�e$w�M�@�ۡu���ὡ���v�I�I�@�v�ƯB���w�a�I�V$n��$l",
		"dodge":		-40,
		"damage":		25,
		"damage_type":	"���"
	]),
	([	"name":			"�n���T��",
		"action":	        "$N�⤤$w�@�ݡM�@�ۡu�n���T�ءv�H�@�өǲ������ש�$n�U�L���h",
		"dodge":		-40,
		"damage":		30,
		"damage_type":	"���"
	]),
        ([
		"name":			"�g���J��",
		"action":		"$N�⤤�@��M�ϩۡu�g���J���v�M���$w�@�@���ۤ@�@�����a��V$n��$l",
		"dodge":		-50,
		"damage":		100,
		"damage_type":   "�@��"
        ]),
	([	"name":			"������[",
		"action":		"$N�@�ۡu������[�v�⤤$w�R�X�@���@�v���V$n����",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("�A�����O�����M�S����k�m�H���@�k, �h�m�Ǥ��O�A�ӧa�C\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("�A��������@���@�l�~��m�@�k�C\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�A�����O�ή𤣰��M�S����k�m�ߴH���@�k�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�A���۩Ҿǽm�F�@�M�H���@�k�C\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

