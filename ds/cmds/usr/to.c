// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.
//void stop_msg(string yn,string arg, object me);

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}


//add by Luky.
int stop_msg(string yn, string arg, object me)
{
	if( yn =="y") me->set_temp("halt_msg_in_edit",1);
	else me->set_temp("halt_msg_in_edit",0);
	me->edit( (: do_to, me, arg :) );
	return 1;
}

int main(object me, string arg)
{
//	write("�z�n�b�s��ɼȰ��Ҧ��T��(�]�A�Q����)��������?(y/n) ");
//	return input_to( "stop_msg", arg, me );
	me->edit( (: do_to, me, arg :) );
	return 1;


}

int help(object me)
{
write(@HELP
���O�榡 : to <���O>

�i�H�@����X�h��H�W����r, <���O>�q�`�O��X�T�������O�p
say , tell , describe , chat , reple ........���C
�d�� : 
 to say
 			�������}�� '.'�M������J�� '~q'�C
 �w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w
 �F�诫�бХD : �w���u���S��
 �ХD�j�ҤH�[�o�b������ : Elon
 �ХD�p�ѱC�[�N�������� : �ھЬX
 �j�̤l�[���V������ : ������R
 .

��X��ù��W�����G�h�O :

�A���D�R�F�诫�бХD : �w���u���S��
�ХD�j�ҤH�[�o�b������ : Elon
�ХD�p�ѱC�[�N�������� : �ھЬX
�j�̤l�[���V������ : ������R
HELP
    );
    return 1;
}

