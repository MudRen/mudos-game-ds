// �ɮ�: /cmds/std/prompt.c
// �@��: Shengsan@DS
// ���: 2000/05/17

#include <ansi.h>

inherit F_CLEAN_UP;

int provar(object me,string type);

int main(object me,string arg)
{

	
	if( strlen(arg) > 50 )
		return notify_fail("�A�����O���ܦr���Ӫ��F�a�C\n");

	if(!arg || arg=="all")
//		arg = "<�ͩR%h �]�k%m ���l%a>";
		if (wiz_level(me)>1)
			arg = "%L> ";	// �Ův�w�]��
		else
			arg = "> ";	// ���a�w�]��

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

	me->set("dssystem/prompt/form",arg);
	write("Ok...\n");
	return 1;
}

int help(object me)
{
     write(@HELP
���O�榡: prompt �Ѽ�

�Ѽ�:
	%%	��� % �Ÿ�
	%h 	�ثe�ͩR�I��
	%H	�̤j�ͩR�I��
	%m	�ثe�]�k�I��
	%M	�̤j�]�k�I��
	%a	�ثe���l�I��
	%A	�̤j���l�I��
	%T	�ثe�ҳB���ɪ�
	%c	�ثe���԰��g���
	%x	�ثe���g���
	%l	�ثe�}��
	%~	���J����r��
	%L	�ثe���u�@�ؿ�(���Ův�ϥ�)

����: �p�G�S���U����Ѽ�, �N�|�H�w�]�ȶi��]�w. �w�]�Ȭ� > 
      �t�~�]�i�f�t�C��Ӱ����, �� help nick

�d��: prompt <$HIR$�ͩR$NOR$ %h>

HELP
    );
    return 1;
}

