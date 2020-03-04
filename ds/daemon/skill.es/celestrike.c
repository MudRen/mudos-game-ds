// celestrike.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�ϥX�@�ۡu�j��ù���v�M�k�x��X���V$n��$l",
		"dodge":		-30,
		"parry":		10,
		"force":		200,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�@�ۡu�j��ù���v�M���x�Ƶꬰ�����V$n��$l",
		"dodge":		-10,
		"parry":		-30,
		"force":		170,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�Ѩ��x�k�u�p��ù���v�M�p���y��ۦ�$n���e�M�@�x��V$n��$l",
		"dodge":		-30,
		"parry":		10,
		"force":		150,
		"damage_type":	"���"
	]),
	([	"action":		"$N���x�@���M�ϥX�u�����T�s��v�M���$n��$l�s���X�T�x",
		"dodge":		10,
		"parry":		-30,
		"force":		260,
		"damage_type":	"���"
	]),
	([	"action":		"$N���x�e�F�Ӱ��M�k�x���X�M�@�ۡu�F�ʤ��蹪�v���V$n$l",
		"dodge":		-20,
		"parry":		-30,
		"force":		240,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�u���p�C�P�_�v�M���δ��@�C�B�P�ɦV$n��$l�X�x����",
		"dodge":		-70,
		"parry":		-10,
		"force":		280,
		"damage_type":	"���"
	]),
	([	"action":		"$N�R���n�M�@�ۡu��٤E���ѡv���x�֤O���X",
		"parry":		-40,
		"force":		320,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�m�Ѩ����x�����Ť�C\n");
	if( (int)me->query_skill("celestial", 1) < 20 )
		return notify_fail("�A���Ѩ����\\���Ԥ����M�L�k�m�Ѩ��x�k�C\n");
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�A�����O�Ӯz�M�L�k�m�Ѩ��x�k�C\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�A����O�����F�M�𮧤@�U�A�m�a�C\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("�A�����O�����F�M�𮧤@�U�A�m�a�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}
