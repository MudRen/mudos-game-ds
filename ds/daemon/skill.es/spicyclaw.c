// spicyclaw.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N���x�L���M�k��@���ϥX�@�ۡu�r�s����v�M��V$n��$l",
		"dodge":		-30,
		"parry":		-70,
		"force":		160,
		"damage_type":	"���"
	]),
	([	"action":		"$N���a�@���ਭ�M����@½�u�����v����$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"���"
	]),
	([	"action":		"$N���l�L�סM�H�Y��X�@�B�M���⩿�x�����ϥX�u���Ǥ�v�M��V$n��$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		120,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�u�C�D�Q�q�A�v�M����ƷȲ��`���$n��$l��h",
		"dodge":		10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"���"
	]),
	([	"action":		"$N�����̡M�k�x���ơM�@�ۡu�٤W�g�l�v���V$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		150,
		"damage_type":	"���"
	]),
	([	"action":		"$N�ϥX�u����M�i�v�M����D�_�M�N�����b���a�e���$n$l��X�@�}",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"���"
	]),
	([	"action":		"$N�k��b$n$l���L�M�H��@�ۡu�H�ҤW���v�����S�V�P�@�����",
		"parry":		-90,
		"force":		100,
		"damage_type":	"���"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�m�o�y�­��⥲���Ť�C\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("�A�����O�Ӯz�M�L�k�m�o�y�­���C\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("�A����O�����F�M�𮧤@�U�A�m�a�C\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("�A�����O�����F�M�𮧤@�U�A�m�a�C\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		switch(random(3)) {
			case 0: return "�Ať��u�ذաv�@�n���T�M�����O���H���n���T\n";
			case 1: return "$N�l�O�@�R�M$n��$l�o�X�u�ءv�a�@�n�z�T�T\n";
			case 2: return "�uť��$n��$l�u�ءv�a�@�n ...\n";
		}
	}
}
