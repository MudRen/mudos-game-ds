// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N�Ϥ@�ۡu�j���۹q�v�M�⤤$w�ۤ@���e����V$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�Ѥs���v�C�����u�����H�v�v�M$w�s���C���N�N�٦V$n��$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N�@�ۡu�ݶ��ӳ��v�M�a���ƶ}�ƤءM�⤤$w�٦V$n��$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"�ζ�"
	]),
	([	"action":		"$N�⤤$w���c���i�M�@���u�B����i�v���$n��$l��X�@�C",
		"dodge":		-40,
		"damage_type":	"���"
	]),
	([	"action":		"$N�a���@�D�M�⤤$w�@�ۡu���Źp���v���$n��$l�ױר�X�@�C",
		"dodge":		-40,
		"damage_type":	"���"
	]),
	([	"action":		"$N��$w�̪Ť@���M�@�ۡu�_�ۯT�ϡv��V$n��$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�A�����O�����M�S����k�m���v�C�k�C\n");

	if( (string)me->query_skill_mapped("force")!= "snowshade-force")
		return notify_fail("���v�C�k�����t�X�Ѥs�]�Ъ��W�����v�ߪk�~��m�C\n");

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
		return notify_fail("�A�����O�ή𤣰��M�S����k�m�߳��v�C�k�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�A���۩Ҿǽm�F�@�M���v�C�k�C\n");
	return 1;
}
