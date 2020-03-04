// gouyee.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("max_mana") < (int)me->query_skill("gouyee") * 5 )
		return notify_fail("�A���]�O�����M�L�k���@�\\��ߪk���y�ڡC\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�\\��ߪk�u��ξǪ��M�άO�q�B��(exert)���W�[���m�סC\n");
}

string exert_function_file(string func)
{
	return CLASS_D("taoist") + "/gouyee/" + func;
}