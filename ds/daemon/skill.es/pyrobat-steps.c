// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
	"���O$n�����Ʃ��M�����@�a�M���w�׶}�C\n",
	"$n���H�N��M���a���@�Ǯ��}�F�T�ءM�׹L�F�o�@�ۡC\n",
	"�i�O$n�����@���M$N�o�@�ۼ��F�ӪšC\n",
	"�o��$n�����I�a�M����«�}�ƤءM���F�}�h�C\n",
	"$n���ηL�̡M����L�I�a�׶}�F$N�o�@�ۡC\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�A����O�Ӯt�F�M����m�������k�C\n");
	me->receive_damage("kee", 30);
	return 1;
}
