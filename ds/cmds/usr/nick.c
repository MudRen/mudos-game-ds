// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }


// �󥿬� 13*2 �U�r��(�쥻30) - Shengsan@DS -
int main(object me, string arg)
{
        string tmp;
        tmp = COLOR_D->clear_withinansi(arg);
        if( !arg ) return notify_fail("�A�n���ۤv������︹�S\n");
        if( strlen(tmp) > 13*2 )
                return notify_fail("�A���︹�Ӫ��F�M�Q�@�ӵu�@�I���B�T�G�@�I���C\n");


	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg,"\n","");
	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
���O�榡 : nick <�~��, �︹>
 
�o�ӫ��O�i�H���A���ۤv���@���T�G���W�����Y�ΡM�A�p�G�Ʊ�b�︹��
�ϥ� ANSI ������r�������C��M�i�H�ΥH�U������r��R

$BLK$ - �¦�		$NOR$ - ��_���`�C��
$RED$ - ����		$HIR$ - �G����
$GRN$ - ���		$HIG$ - �G���
$YEL$ - �g����		$HIY$ - ����
$BLU$ - �`�Ŧ�		$HIB$ - �Ŧ�
$MAG$ - �L����		$HIM$ - ������
$CYN$ - �ź��		$HIC$ - �ѫC��
$WHT$ - �L�Ǧ�		$HIW$ - �զ�
 
�䤤�t�Φ۰ʷ|�b�r����ݥ[�@�� $NOR$�C

HELP
        );
        return 1;
}
