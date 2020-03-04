// sttormdance.c

inherit SKILL;

string *dodge_msg = ({
	"���O$n���k���F�M�����a�ƤF�}�h�T\n"
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "�k��" )
		return notify_fail("�C�_�ѴP�R�u���k�ʤ~��m�C\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("�A���F�ʤ����M�S����k�m�C�_�ѴP�R�C\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("�A���믫�Ӯt�F�M����m�C�_�ѴP�R�C\n");
	me->receive_damage("sen", 30);
	return 1;
}
