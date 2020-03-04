// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n�@�ۡu�ѿY���ϡv���������a�פF�}�h�C\n",
	"�u��$n���v�@�̡M�@���u��梶èB�v���w�צb�C�ؤ��~�C\n",
	"$n�ϥX�u������v�v�M�����P�P�a�{�L�C\n",
	"$n�����@�I�M�@�ۡu�v�v�Ѽϡv�˪ŦӰ_�M�פF�}�h�C\n",
	"�i�O$n�Ϥ@�ۡu���ʥɿšv�M���l�����ƤF�}�h�C\n",
	"$n���v�L�ʡM�w�g�Ǥ@�ۡu�}�������v�����{�L�C\n",
	"���O$n�@�ۡu��������v�ϥX�M���w¶��$N����T\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�A�����O�����M�S����k�m�˶äC�P�B�C\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�A����Τ��O�����M����m�˶äC�P�B�k�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
