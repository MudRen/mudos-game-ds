// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�Ϥ@�ۡu�p�j����v�M�⤤$w�p�@���ȳD���V$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�ʤs�C�k�����u�Ťs���y�v�M�C���N�N�٦V$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N�@�ۡu�s���Ӧ�v�M���ΰ~�M�ƥX�ƤءM�⤤$w�٦V$n��$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N�⤤$w���c���i�M�@���u����F�@�v���$n��$l��X�@�C",
		"dodge":		-40,
		"damage_type":	"���"
	]),
	([	"action":		"$N�a���@�D�M�⤤$w�@�ۡu�����m�a�v���$n��$l�ױר�X�@�C",
		"dodge":		-40,
		"damage_type":	"���"
	]),
	([	"action":		"$N��$w�̪Ť@���M�@�ۡu���l�޸��v��V$n��$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"���"
	]),
	([	"action":		"$N�⤤$w�V�~�@���M�Ϥ@�ۡu�h�t����v�Ϥ���$n$l�@�C��h",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"���"
	]),
	([	"action":		"$N��C�W�e�M���Τ@��⤤$w�Ϥ@�ۡu�Ũ���i�v�e�X�@�D�����٦V$n��$l",
		"dodge":		-30,
		"damage":		10,
		"damage_type":	"�ζ�"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�A�����O�����M�S����k�m�ʤs�C�k�C\n");

	if( (string)me->query_skill_mapped("force")!= "fonxanforce")
		return notify_fail("�ʤs�C�k�����t�X�ʤs�����\\�~��m�C\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("�A��������@��C�~��m�C�k�C\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�A�����O�ή𤣰��M�S����k�m�߫ʤs�C�k�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�A���۩Ҿǽm�F�@�M�ʤs�C�k�C\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("swordsman") + "/fonxansword/" + action;
}
