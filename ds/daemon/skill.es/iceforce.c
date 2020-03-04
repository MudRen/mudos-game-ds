// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("�N�H�\\�u��ξǪ��M�άO�q�B��(exert)���W�[���m�סC\n");
}

string exert_function_file(string func)
{
	return CLASS_D("dancer") + "/iceforce/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	mixed foo;

	foo = ::hit_ob(me, victim, damage_bonus, factor);
	if( intp(foo) && (damage_bonus + foo > 0) ) {
		if( random(me->query_skill("iceforce")) > (damage_bonus + foo) ) {
			victim->receive_wound("kee", (damage_bonus + foo));
			victim->apply_condition("iceshock", factor/3);
			return "$N���ۦ����ۤ@�ѳ��H�L�񪺫l���ϱo$n���T���F�ӴH���C\n";
		}
	}
	return foo;
}