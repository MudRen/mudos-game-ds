// serpentforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	if( !environment(me)->query("resource/water") )
		return notify_fail("���\\�u��b�������a��m�C\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("�A���𤣰��C\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("�A�����O����");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string exert_function_file(string func)
{
	return CLASS_D("beggar") + "/serpentforce/" + func;
}
