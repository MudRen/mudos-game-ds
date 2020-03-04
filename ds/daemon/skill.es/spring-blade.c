// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�Ϥ@�ۡu�K���ؤH�K�v�M�⤤$w�����Ʀa�V$n��$l�٥h�T",
		"damage":		200,
		"dodge":		70,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N���b�A���M$w�H�ۤ@�ۡu���s��H���v�ѤU�ӤW����$n��$l",
		"damage":		40,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N���Τ@��M�@�ۡu����v�H���v$w�M�����w�M�٦V$n��$l",
		"damage":		20,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N�R��$w�M�@�ۡu�h���H�H���v�����L�ۦa�A�V$n��$l",
		"damage_type":	"����"
	]),
	([	"action":		"$N�⤤$w�@�̡M�@�ۡu�żv�S�H���v��$n��$l�ױ׬�X�@�M",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N���M�L�ӡM�W�l�o�O�M�@�ۡuĪ���H�H�v�v���A$n$l",
		"damage":		40,
		"damage_type":	"����"
	]),
	([	"action":		"$N���B�����M�Ϥ@�ۡu�m���`�H��v�M���N�N�٦V$n��$l",
		"damage":		40,
		"damage_type":	"����"
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("�A��������@��M�M�~��m�M�k�C\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("�A����O�����m�o���M�k�M�٬O���𮧥𮧧a�C\n");
	me->receive_damage("kee", 40);
	return 1;
}
