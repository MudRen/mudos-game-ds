// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("�A������ӭ��M�L�k�׷ҤѮv���D�C\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�k�N���ޯॲ���ξǪ��άO�q��Ԥ�����g��C\n");
}
