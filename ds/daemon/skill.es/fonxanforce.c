// fonxanforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("�ʤs�����\\�u��ξǪ��M�άO�q�B��(exert)���W�[���m�סC\n");
}

string exert_function_file(string func)
{
	return CLASS_D("swordsman") + "/fonxanforce/" + func;
}
