#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "name":         HIC"�C�s�X��"NOR,
        "action":
        "$N"HIW"��_�����A�@�ۡu"+HIC"�C�s�X��"+HIW"�v�⤤��$w"HIW
        "��V$n"HIW"��$l��h�C" NOR,
//      "dodge":        -20,
        "damage":       35,
        "damage_type":  "���"
    ]),
    ([  "name":         MAG"�m���e��"NOR,
u"
        "$N"HIW"���C�b�����e��$n"HIW"�����ؤ��W�C"NOR,
//      "dodge":        -10,
        "damage":       10,
        "damage_type":  "�ζ�"
    ]),
    ([  "name":         BLU"����ѲP"NOR,
        "action":       "$N"HIW"����L�V�e�ɡA�@���u"+BLU"����ѲP"+HIW
        "�v�A���C���V$n"HIW"��$l�A�F�L�h�C"NOR,
        "dodge":        -30,
        "damage":       50,
        "damage_type":  "���"
    ]),
    ([  "name":         HIM"��e��U"NOR,
        "action":       "$N"HIW"��CŸ�ʡA�p�A��ۮi�����A�Ӧ^���d�A�@�ۡu"+HIM
        "��e��U"+HIW"�v�u�̱o$n"HIW"���Ἲ�áA\n"
        "�P��$N"HIW"�۰_�⤤��$w"HIW"��M�d�V$n"HIW"��$l�C"NOR,
//      "dodge":        -20,
        "damage":       20,
        "damage_type":  "�ζ�"
    ]),
    ([  "name":         HIG"�M���p�u"NOR,
        "action":       "$N"HIW"�C�`���_�A�C�y�W½�A�@���u"+HIG"�M���p�u"+HIW
        "�v�A���O���V�ۤv��B�A�{���|�M�۶��@��C\n"+
"NOR,
        "dodge":        -30,
        "damage":       40,
        "damage_type":  "���"
    ]),
    ([  "name":         HIG"���^����"NOR,
        "action":       "$N"HIW"����L�V�e�ۡA�N�C�������e�F�ө������ݫe�A"
��"
        +HIW"�v�N�⤤$w"HIW"'��$n"HIW"��$l�@�e�C"NOR,
        "dodge":        -15,
        "damage":       20,
        "damage_type":  "�ζ�"
    ]),
    ([  "name":         HIY"�����i��"NOR,
"
        "�����Z���b�G�L�߸��l�@��A\n"
HIY
        "�����i��"+HIW"�v����V$n"HIW"���U�L�C"NOR,
        "dodge":        -10,
        "damage":       20,
        "damage_type":  "�ζ�"
    ]),
    ([  "name":         HIC"�Q�U���"NOR,
        "action":       "$n��V$N��$l�����A$N�ਭ�^��$n��$l�����A"
  "�A����$n�Q�A��V$N�ɡA\n$N"HIW"�׼C�U���A�@���u" + HIC
        "�Q�U���"+HIW"�v�A�⤤$w"HIW"�Ʀ��h�h�C�v�A��V$n"HIW"���Ѩ��޹D�C"NOR,
        "dodge":        -20,
        "damage":       20,
        "damage_type":  "���"
    ]),
    ([  "name":         HIM"������b"NOR,
        "action":       "$N"HIW"�|�C�V$n"HIW"��$l���A�L�h�A$n"HIW
        "�����{�L�H�Y�V$N"HIW"��$l��F�L��"
        "\n�A$N"HIW"�C�����R���b�a�W�I�F���I�A�@�ۡu"+HIM"������b"+HIW
        "�v�A�N�⤤��$w"HIW"��V$n"HIW"��$l�C"NOR,
        "dodge":        -10,
        "damage":       15,
        "damage_type":  "�ζ�"
    ]),
    ([  "name":         HIG"�p������"NOR,
"
        "$n"HIW"�����X���V$N"HIW"��$l�A\n����$N"HIW"��_�Y�ӷL�L�@���A"
        "�⤤$w"HIW"�ݰʡA�@���u"+HIG"�p������"+HIW"�v�A�I�V$n"HIW"��$l�C"NOR,
        "dodge":        -10,
        "damage":       25,
        "damage_type":  "�ζ�"
    ]),
   ([  "name":         HIY"�}���]��"NOR,
        "action":       "$N"HIW"�H�u�������A��C�e�F�ӥb��A$n"HIW
        "�@�ݥ��Q�X���I�V$N"HIW"��$l���ɡA\n$N"HIW
R,
        "dodge":        -10,
        "damage":       25,
        "damage_type":  "���"
    ]),
    ([  "name":         HIY"�h���p�y"NOR,
ʥX"
        "�ǳ������ɡA\n$N"HIW"��_�C�b�A�@���u"+HIY"�h���p�y"+HIW
        "�v�A�⤤$w"HIW"�w�����I�V$n"HIW"��$l�C"NOR,
        "dodge":        -15,
        "damage":       25,
        "damage_type":  "���"
    ]),
    ([  "name":         HIR"��î�{��"NOR,
        "action":       "$N"HIW"���S�L���A���ਭ�ߨë��C�V�U���R�X�h�h�A"
        "�ݦ������몺�C�v�@������A\n��$n"HIW"�Q����|�i�𤧮ɡA$N"HIW"���ܤ@��"
        "�u"+HIR"��î�{��"+HIW"�v�A�n�\\�C���A"
        "\n�⤤$w"HIW"���X�F�@�D�����٦V$n"HIW"��$l"NOR,
        "dodge":        -15,
        "damage":       25,
       "damage_type":  "�ζ�"
    ]),
});
int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_force") < 50 )
        return notify_fail("�A�����O�����M�S����k�m�ɤk�C�k�C\n");
    if( !(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "sword" )
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
int practice_skill(object me)
{

    if( (int)me->query("kee") < 30
    ||  (int)me->query("force") < 3 )
        return notify_fail("�A�����O�ή𤣰��M�S����k�m�ߥɤk�C�k�C\n");
    me->receive_damage("kee", 30);
    me->add("force", -3);
    return 1;
}

