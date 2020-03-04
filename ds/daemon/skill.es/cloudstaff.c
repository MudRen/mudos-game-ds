// cloudstaff.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�Ϥ@�ۡu�ѥ��E�{�v�M�⤤$w���V$n�U�L�T",
		"damage":		40,
		"dodge":		10,
		"parry":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N���_$w�M�@�ۡu�B��촸�v��V$n$l�T",
		"damage":		40,
		"dodge":		20,
		"parry":		-60,
		"damage_type":	"����"
	]),
	([	"action":		"$N��L�⤤$w�M�ϥX�u�B���g�N�v���V$n$l�T",
		"damage":		40,
		"dodge":		10,
		"parry":		-40,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ϥX�@�ۡu���s�ﶳ�v�M$w�@�����V$n$l�T",
		"damage":		40,
		"dodge":		10,
		"parry":		-40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	if( (int)me->query("str") + (int)me->query("max_force") / 10 < 50 )
		return notify_fail("�A���M�O�٤����M�]�\\�ӽm�@�m���O�ӼW�j�O�q�C\n");

	return 1;
}

int valid_enable(string usage)
{
	return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "staff" )
		return notify_fail("�A��������@�ڤ���Ϊ̬O�������Z���M�~��m���k�C\n");

	if( (int)me->query("kee") < 60 )
		return notify_fail("�A����O�����m�o�����k�M�٬O���𮧥𮧧a�C\n");
	me->receive_damage("kee", 60);
	return 1;
}
