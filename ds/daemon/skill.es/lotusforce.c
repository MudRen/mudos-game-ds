// lotusforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism") < (int)me->query_skill("lotusforce") )
		return notify_fail("�A���j����k�׬������M�L�k��|�󰪲`�����ؤߪk�C\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("���ؤߪk�u��ξǪ��M�άO�q�B��(exert)���W�[���m�סC\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bonze") + "/lotusforce/" + func;
}
