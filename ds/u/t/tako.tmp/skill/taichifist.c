
#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "action":   "��$n����$N����ɡA$N��M�ϥX�@���u"HIC"��������"NOR"�v�A�����O�q��`�����x�A���թ�$n���W���h�C",
        "dodge":      20,
        "parry":      90,
        "damage":     80,
        "force":     250,
        "damage_type":  "�Y����ˡA�ö^�F�ӥ|�}�¤�",
    ]),
   ([  "action":   HIW"$N�H�R��ʡA$n�������i���A��$N�����W��F�@�x�A�S�Q��$N�@�ۡu"HIY"�ɤO�ϤO"HIW"�v�A$n�ϾD�ۮa�x�k�ϼ��C"NOR,
        "dodge":      50,
        "parry":      90,
        "damage":     90,
        "force":     300,
        "damage_type":  "���",
    ]),
   ([  "action":   HIW"$N���ʦp�s�A$n�ߧY�m��A$N��M�ϥX�u"HIR"�|��"HIY"��"HIC"�d��"HIW"�v�A�L�a�j���¤O��$n��$l���h�C"NOR,
        "dodge":     10,
        "parry":     50,
        "damage":   150,
        "force":    400,
        "damage_type":  "���",
    ]),
   ([  "action":   "$n�S�X���j���}��A$N�@�������i���A�ߧY�I�i���k�A�@�����w�g��F$n�����e�A�@���u"HIW"�շ��m�G"NOR"�v�A$n�������D�즳�p�d�礧�O�������C"NOR,
        "dodge":     -20,
        "parry":      30,
        "damage":     80,
        "force":     250,
        "damage_type":  "��ˡA�����򺵿ߤ@�ˡA���_���Ӥ]�}�l�n�n�̮̪�",
    ]),
   ([  "action":   "$N�}��ӷ��K���}�A���v��M�U�k���_�ӡA��M�@���A�u"HIG"�C�s����"NOR"�v�A$n�@�L�wĵ���A�I���w�r�M����",
        "dodge":       20,
        "parry":       50,
        "damage":      70, 
        "force":      300,
        "damage_type":  "��ˡA�åѤf���R�X�A��",
    ]),
   ([  "action":   HIW"$N�B�_�j�l�����O�A�@���u"HIC"����"HIG"����"HIW"�v�A�L�Τ��o��ĭ�t���ˤO�����O��$n�����W�e�g�ӥh�C"NOR,
        "dodge":      20,
        "parry":      50,
        "damage":     70,
        "force":     250,
        "damage_type":  "�ƹD�ζ�",
    ]),

});
int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("�Ǥӷ��������n�Ť��C\n");
    if( (int)me->query("max_force") < 50 )
        return notify_fail("�A�����O�ӧC�F�a�I�h�m�줭�Q�A�ӾǡC\n");
    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("sen") < 30  )
        return notify_fail("�A���믫�L�k�����F�M�𮧤@�U�A�m�a�C\n");
    if( (int)me->query("force") < 5 )
        return notify_fail("�A�����O�����M�S����k�m�ߤӷ����C\n");
    if( (int)me->query("kee") < 30 )
        return notify_fail("�A���𤣰��M�S����k�m�ߤӷ����C\n");

    me->receive_damage("kee", 30);
    me->add("force", -5);
    return 1;
}


