// pwd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		write("Cwd: " + (string)me->query("cwd") +  "\n");
		write("Cwf: " + (string)me->query("cwf") +  "\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
���O�榡 : pwd
 
�o�ӫ��O�|��ܥX�A�ثe���u�@�ؿ� (cwd) �Τu�@�ɮ� (cwf).
'update' ���[�ѼƮɫK�|��s�A�� cwf.
 
HELP
    );
    return 1;
}
