// fonxanforce.c

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("封山派內功\只能用學的或是從運用(exert)中增加熟練度。\n");
}