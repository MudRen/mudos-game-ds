// fonxanforce.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("�ʤs�����\\�u��ξǪ��άO�q�B��(exert)���W�[���m�סC\n");
}