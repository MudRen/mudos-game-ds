// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50 )
		return notify_fail("�A�����𤣰��M�L�k�⮩�󰪲`���Ѩ����\\�C\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�Ѩ����\\�u��ξǪ��M�άO�q�B��(exert)���W�[���m�סC\n");
}

string exert_function_file(string func)
{
	return CLASS_D("fighter") + "/celestial/" + func;
}

