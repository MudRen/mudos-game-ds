// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"�s�]�ûR",
		"action":		"$N�Ϥ@�ۡu�s�]�ûR�v�M�⤤$w�g���J�B��a�V$n��$l�s��ƼC",
		"dodge":		50,
		"damage":		170,
		"damage_type":	"���"
	]),
	([	"name":			"�F����",
		"action":		"$N���Τ@��M�@�ۡu�F���񨭡v$w�٦V$n��$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"���"
	]),
	([	"name":			"�ʰ��]��",
		"action":		"$N�R��$w�M�@�ۡu�ʰ��]��v���۰{�{�C����V$n��$l",
		"dodge":		-40,
		"damage_type":	"���"
	]),
	([	"name":			"�j���d��",
		"action":		"$N�⤤$w�@�ݡM�ϥX�u�j���d���v��$n��$l��X�@�C",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"���"
	]),
	([	"name":			"���v�l�l",
		"action":		"$N�⤤$w�C���ɪ��M�@�ۡu���v�l�l�v��$n$l��h",
		"dodge":		-60,
		"damage":		20,
		"damage_type":	"���"
	]),
	([	"name":			"��X����",
		"action":		"$N�⤤$w����$n$l�M�@�ۡu��X���ۡv�o�X�G�H�C���h",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("�A�����O�����M�S����k�m�����l��C�C\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("�A��������@��C�~��m�C�k�C\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�A�����O�ή𤣰��M�S����k�m�ߤ����l��C�C\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�A���۩Ҿǽm�F�@�M�����l��C�k�C\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n�A��Mı�o�@�Ѵc��ĤW���Y�M�uı�o�Q���H....\n\n" NOR);
		me->add("bellicosity", 1000);
	} else
		me->add("bellicosity", 100);
}
