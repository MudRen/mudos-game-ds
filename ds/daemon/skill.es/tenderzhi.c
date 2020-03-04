// tenderzhi.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N����@���M�@�ۡu��ӱĤ�v�k���I�V$n$l",
		"dodge":		-30,
		"parry":		30,
		"force":		80,
		"damage_type":	"���",
		"weapon":		"�k�⭹��",
	]),
	([	"action":		"$N�Ϥ@�ۡu���������v�M���v���e����M��M�@�ਭ���⩹$n��$l�I�h",
		"dodge":		-30,
		"parry":		30,
		"force":		90,
		"damage_type":	"���",
		"weapon":		"���⤤��",
	]),
	([	"action":		"$N���k�y�y�M����@���ϥX�u�h�F¯��v��$n��$l�I�h",
		"dodge":		-30,
		"parry":		30,
		"force":		140,
		"damage_type":	"���",
		"weapon":		"���⤤��",
	]),
	([	"action":		"�u��$N�ָy�@�\\�M�~�M�ƥX�ƤءM�k�ⶶ�ۨӶդ@�ۡu��X�����v��$n��$l�I�h",
		"dodge":		-30,
		"parry":		30,
		"force":		90,
		"damage_type":	"���",
		"weapon":		"�k�⭹��",
	]),
});

int valid_learn(object me)
{
	if( (string)me->query("gender") != "�k��" )
		return notify_fail("�X�i���O�u���k�l�~��m���Z�\\�C\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�m�X�i�������Ť�C\n");
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
	if( (int)me->query("sen") < 30 )
		return notify_fail("�p���믫�L�k�����F�M�𮧤@�U�A�m�a�C\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("�p�����O�����F�C\n");

	me->receive_damage("sen", 30);
	me->add("force", -10);

	return 1;
}
