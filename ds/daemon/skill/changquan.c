// changquan.c �ӯ�����
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
"�u��$N���Τ@�G�A�j���n���@�ӡy�ĤѬ��z���$n����l�I�a�{�F�L�h",
"$N����@���A�k���B��A�@�ۡy�ޯ�M�D�z�K��$n��$l�۩I�L�h",
"$N�k���b$n�����@�̡A���x�ϤF�ӡy��������z��$n��$l���R�@��",
"$N�B�i�@�I�A�����Զ}�A�k���a���A�@�ۡy�ª�Ǥߡz�դ��i�צa���V$n$l",
"�u��$N�Զ}�[���A�@�ۡy�����e�աz�ϱo��꦳���C���U�o���_�@�}��V$n$l",
"$N���o���_�A�j�ܤ@�n�G�ݧڳo�ۡy�s��ۥ�z�I \n���⩹$n����@�ۡA�k���K��$n�����{�F�L�h",
"$N�Զ}��}�B�A���x�ϤF�ӡy�p�ʦ����z��$n��$l�@��",
"�u��$N�B����O�A�@�s�T�����V$n$l�A�O�D�@�����L�@���I \n�o�@�۪��W�r�٬۷����A�s�@�y�����T�|�z",
"$N����@�a�A�N�ըϤF�ӡy�Ѿ�L�ڡz�A�k�L���V$n��$l",
"$N�@���ਭ�A���x�@�ݡA�k�x�Ϥ�ϤF�ӡy�W�A�ؤs�z��$n���Y�@�A",
"$N�@�ۡy���۫ʤѡz�A�U�b���k�}�J�B�W�e�A����ƴx�A�V�e���ۤW��$n��$l",
"$N����V�e�ĥX�A�@���y�ĨB���x�z�A�������^�y�ګ�A�A�V�e�H�����x�����ӥX",
"$N������B�k��A�k��V�k�N�X�A���ⶶ���@�ӡA�y�^�����N�z��V$n��$l",
"$N���_���L�A�����k�L���W�ߨB���w�A�y��P�𰫡z���L���զV�e���ަӥX",
"$N�@�ۡy�i�B�Ĵ��z�A�W�k�B�ܥ��}�ǡA����H���Į��V$n�����ӥX",
"$N�X�@���y�}�B�ĥ��z�A���}�V����X�A����ɶq���C�A�Ԧ^����A�k���V�e�����ӥX",
"$N�@���y��׻��x�z�A�����L�V�U���A���ͫ�Ԥ��աA������A�k��ƴx�V�e�����ӥX",
"$N�O����}�b�B���w���ʡA�y�P�l�ۤ��z�k�x��a½�x�A����H�ϴx�ѥk�x�W�誽��ӥX",
"$N�X�y��B�_�y�z�A�k�B��e�A�������B�۩w�A���զ��^����A�k��V�e�H���y�����ӥX",
"$N�B�k���k�ᥪ�A�s��W�B�A�@���y���ĽĴ��z�k���V$n��$l�����ӥX",
"$N�Ԧ^�k��A����Ʈ��V�e�����ӥX�A�P�ɡy���ĥk��z�k�L�V�e����ӥX",
"$N�k�}�V�e���B�A�����B���w�A�y�����D���z�b���⦬�^�y�ڡA�k���V�k�����ӥX",
"$N�@���y�^���W�ߡz�A�k����a½�x�A���x�ƤN��פN����A�����@������A��������",
"$N�@�ۡy�r���סz�A�k�L�V�e����ӥX�A�����B���w�A����H�ϤN��N�w$n",
"$N�@�ۡy��P�W�ߡz�����k�L�A�N���ߧ��󥪸}�W�A�H�۩ް_���աA�k�x�V$n���D�ӥX",
"$N��դ��ʡA�@�ۡy«�B���ߡz�ֳt«�e�A���_�k�L�V�e�ֽ�A�P�ɥ��x�V�e�����ӥX",
"$N�V�e�@�ۡy���s�����z�A�����ܴx�����A���k�ᥪ�A�s��V$n��$l���X",
"$N�V�e�@«�A�y�r��X�}�z�N���N��V��^�ġA�P�k�N��P�m����A�N�J�ӥX",
"$N����O����N�⫺�դ��ܡA�y�¤Ѥ@�ޡz�k�L�����A�V�e�H�L������$n$l",
"$N�ӤF�ӡy��B�_�y�z�A���I�a������B���w�A�k�����զV�e�ϽĦӤW",
"$N�k��ƴx�A�y�Ĥ�Ĵ��z�V�e��ĦӥX�A�S���թԦ^�k��A�N�����V$n���X",
"$N�V�e�ĥX�T�B�A�@���y�T�B�殱�z�������k�ᥪ�A�s��V$n�����ӥX",
"$N�@���y�����D���z�A�k�}�V�e���B�����B���w�A���⦬�^�y�ڡA�k�������ӥX",
"$N�@�ۡy�רB����z�L�V�k��A���W�ߨB���w�A�P�ɥk��ƴx�V$n����",
"$N����ѥk�x�W�誽��ӥX�A�o�ۡy���ﶳ��z����$n��$l",
"$N�k��ѥ��x�W�誽��ӥX�A�@�ۡy�k�ﶳ��z���V$n��$l",
"$N�V�������X�A�@���y���B�_�y�z�A�k��ƨy�A�V����$n��ӥX",
"$N�X�y�I�B���Y�z�A�k�L���B���w�A�����D�_�A�ǵ����ݤ��O�V�ⰼ�Y���ӥX",
"$N���B�r�B�A�y���B�L��z�������O�V�W�Ϭ�ӥX�A���ۦ��^�k�x�A�V�U����",
"$N�X�@�ۡy½�����x�z�A�����V���ॿ�A����ƤN��A�k��H����x�V$n�����ӥX",
"$N�@�ۡy���������z�A���k��P�ɥH�ﶳ��V$n��X�A�s���T��",
"$N�@���y�^����ݡz�A���L�V�e��X�����L�A�P�ɥ���^�ġA�k��e���V$n",
"$N����k�ϥ����@�ӡA�@���y�^�D�Į��z�k�⦱�y�W�[�A�����V$n$l�����ӥX",
"$N�O����}�b�B���w���ʡA�@�ۡy���B�Ĥ�z�A����H�p���V�W���",
"$N�������L�B�k�U���A�y�ۨ{�Ĵ��z���ⶶ�եH�ۨ{���V$n$l�����ӥX",
"$N�����ʦӦ^�@��k�ӡA�@�ۡy½�ѼA�a�z�k��H�p���V$n�若�ӥX",
"$N����V�W�D�_�A�X�y�����D���z�b�k�⦬�^�y�ڤ��ɥ����V$n�����ӥX",
"$N�k�L�V�e�H�p���L�V�e���X�A���ⴤ���y���s�����z�����V$n��$l",
"$N�k�x�ѫ�V�e�ϬD�ӤW�A�M��X�y½�������z����V�ⰼ�H���۴x����",
"$N�X�y�^�B�����z�A�������A����P�ɦV�e���ۦӤW�A���V$n��$l",
"$N����k�ɡA�@�ۡy�Ϩ�����z�A���x���ʡA�k�x�V�k�U��Ϥ�$n$l",
"$N�@���y½�������z�A����H���۴x�V�e�Ϥ��ӥX�A�󭱫e�w��A�o�X�n��",
"$N�k�L�V�e����ӥX�A�y½��b�u�z�������x��½�A�k��ƴx�A����N��$n",
"$N���N�⤣�ʡA�k�x���^�ݫe��l�A�y���ձ��s�z�H�ߴx�V$n�����ӥX",
"$N���^����A�H�Q�r��ʦ�ݫe�A�y��Bť���z�������x�V$n�����ӥX",
"$N�@�ۡy��l�L�k�z�A�����V�W���_�A���L���զV�����$n��$l",
"$N�����k�L�A�N���ߧ��󥪸}�W�A�y��P�W�ߡz�H�۩ް_���աA�k�x�V�e���D�ӥX",
"$N�@���y���^���j�z�A����k�ϡA�����@�ӡA�k�ⷥ�O�U�ϤS���D�ӤW",
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanshou"; }

mapping query_action(object me, object weapon)
{
        return ([
                "action" : msg[random(sizeof(msg))],
                "dodge"  : 40+random(20),
                "parry"  : -20+random(20),
                "force"  : 50+random(150),
                "damage_type" : random(2)?"����":"���",
        ]);
}
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�m�ӯ����������Ť�C\n");
        return 1;
}
int practice_skill(object me)
{
        if( (int)me->query("jing") < 30)
                return notify_fail("�A���믫�L�k�����F�A�𮧤@�U�A�m�a�C\n");
        if( (int)me->query("qi") < 30 )
                return notify_fail("�A�{�b�⨬�ĳn�A�𮧤@�U�A�m�a�C\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("�A�����O�����F�C\n");

        me->receive_damage("qi", 30);
        me->add("neili", -10);

        return 1;
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
        return __DIR__"changquan/" + action;
}

int help(object me)
{
        write(HIC"\n�ӯ������G"NOR"\n");
        write(@HELP
        
    �ӯ������O�N��a�Ǯ��ޡC�N����������ªZ¾���ѹC���N�x�A
���`�᮵�����~�����A�v���ϲM�_���]����a�Ь��ҡ^�A���H����
�����B�ży��¬ӫҪ��ݽá]���۸O���ҡ^�C�����]��a�ګO�u�A��
���\�䥦���ئ��B�I���J�A�]�����\�ڤH���N��ʡA�G�O���F��l��
�����A�ǦܧڳB�w���G�Q�T�@�C�����b�m���ķs�ѡn�B�m�}�O�n�B
�m�֪L���Сn�B�m�Ⱦ����¥޹D���Z�n���\�h�j�N���Ф������O���A
���ѩ������h�æۯ��A�G���|�ǲ߸��֡A�{���|���|���ӯ��|�i����
���̻�h�A�������~�Ӧ����ت��H�o��Y�P���C 

    �ӯ��������D�n���e���G 
    �@�B���N���G�ӯ��|�i�����]�t���С^�B�������]�@���հ���V
<�t����>/�G�������ê�<�t����>/�T���T��/�|���K�Ӧr<�t����>/��
���ٮ���/�����P�C�a�^ 
    �G�B�������G�����ӯ����s�M/�ӯ����M/�ӯ���j�]�t���С^/
��L�j�]�t���С^/�ӯ��˳D��/�Q�X�j�Ρ]�t���С^/���X�ҡ]��l�^
/�G�k���Ҵҡ]�T�H��m�^/���ҡ]���J�N�B�c���B���T�K��m�^
/�ӯ��L�s�@�]�t���С^/�y�P���]�t���С^/�K��j�M�]�t���С^/��
���I�j�j�]�X�j�B���j�B�T���T�\�B��î�j�^/�����\���U�l�]���H
��m�^���C 
    �ӯ������H��Ԭ��D�A���զh�L�k�A�^�����D�n������q�A�ள
���W�����ޡ]���t�}�Ѥ��k�A�������Y���ள��m�^�A�ΦѮ��v�̪�
�����N�O�����o���̦����Y�١��A���U���N�Y�O�������ȫܰ��C�t�~�A
�������Ӥ��e���������I�A�N�O�����������ȡA��߽m�ӯ���������
���v���A�E�Q���H�W���֪̻�h�A�䤤�H�ĤG�Q�G�@�i�ɵج��̡A��
�~�E�Q�C���C

        �ǲ߭n�D�G
                �L
HELP
        );
        return 1;
}
