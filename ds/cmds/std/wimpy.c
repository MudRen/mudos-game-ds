// wimpy.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	int wmp;

	if( !arg ) {
		write("[wimpy]: ��A���u�ͩR�v�C�� " + (int)me->query("wimpy") 
			+ "% �ɴN�|�۰��|�հk�]�C\n");
		return 1;
	}
	if( sscanf(arg, "%d", wmp)!=1 || wmp < 0 || wmp > 80)
		return help(me);

	me->set("wimpy", wmp);
	write("[wimpy]: ��A���u�ͩR�v�C�� " + (int)me->query("wimpy") 
			+ "% �ɴN�|�۰��|�հk�]�C\n");
	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡�R wimpy [<�k�]�ɡu�ͩR�v���ʤ���>]

�o�ӫ��O���A�]�w��u�ͩR�v�ѤU�ʤ����h�֮�( 0% ~ 80% )�M�n�}�l�u��i�v�C
HELP
	);
	return 1;
}

