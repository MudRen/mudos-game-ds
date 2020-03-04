// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *tuned_ch;

	tuned_ch = me->query("channels");
	if( !arg ) {
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("�A�{�b�èS����ť�����W�D�C\n");
		else
			write("�A�{�b��ť���W�D�R" + implode(tuned_ch, ", ") + "�C\n");
		return 1;
	}

	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("���� " + arg + " �W�D�C\n");
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		return 1;
	} else {
		//write("�n���}�Y���W�D�u�n�θ��W�D���ܧY�i�C\n");
		if(CHANNEL_D->can_tune(arg,me))
		{
			tuned_ch += ({ arg });
			me->set("channels", tuned_ch);
			write("�}�� " + arg + " �W�D�C\n");
		}
		else write("�L�k�}�ҳo���W�D�C\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
���O�榡�Rtune [<�W�D�W��>]

�o�ӫ��O���A��ܬO�_�n��ť�Y�@�W�D���T���M�p�G�S�����w�W�D�W�١M�N�|�C�X
�A�ثe��ť�����W�D�M�p�G���w�F�W�D�M��Ӧ�ť�����N�|�����M�Ϥ����}�C

�p�G�A��@�ӨS����ť�����W�D���ܡM�|�۰ʱN�����}�C
�n��@���W�D���ܡM�u�n�ΡR

<�W�D�W��> <�T��> ....

�Ҥl�R
  chat hello everyone!
  
�A�i�H�� help channels �d�ߥثe�������W�D�i�H��ť�C

see also : shout
HELP
	);
	return 1;
}

