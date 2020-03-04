// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�Ϥ@�ۡu�j�Q����v�M���$n��$l�u�I�v�a�@��",
		"dodge":		-40,
		"parry":		40,
		"damage_type":	"���"
	]),
	([	"action":		"$N���_���Y�M�@�ۡu�Ƴ��V���v�K��$n��$l�۩I�L�h",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"���"
	]),
	([	"action":		"$N�����̡M�k���u�t�Vť�ܡv��$n��$l���X",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"���"
	]),
	([	"action":		"$N�B�i�@�I�M�����Զ}�M�k���ϥX�u��s��u�v���V$n$l",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�m�h�a���k�����Ť�C\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�A����O�����F�M�𮧤@�U�A�m�a�C\n");
	me->receive_damage("kee", 30);
	return 1;
}
