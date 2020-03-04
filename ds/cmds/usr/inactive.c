// File : "/cmds/usr/inactive.c"
// Last Modify : -Alickyuen@ds- �s�Winactive ���Witem checking ,�H��robot 

inherit F_CLEAN_UP;

string *club_area = ({
	"/open/world1/cominging/area/dragon/",
	"/open/world1/god_club/",
	"/open/world1/baal/ming_club/",
	"/open/world1/acme/area/sky/",
	"/open/world1/acme/area/moon/",
});

int help(object me);
void delay(object me);

int main(object me, string arg)
{
	object *obj;

	if( me->query_temp("cmds/inactive") )
		return notify_fail("�A�~��γo�ӫ��O, �A���@�|��A�ϥΧa�C\n");

	foreach(string area in club_area)
	{
		if( strsrch(file_name(environment(me)), area) != -1 ) 
			return notify_fail("���|�d�򤺤���i�J[���m�Ҧ�]�C\n");
	}

	obj = all_inventory(me);

	foreach(object item in obj)
	{
		/*
		if( !item->query_autoload()
		&& strsrch(file_name(item), "open/world") != -1 )
                        return notify_fail("�A���W���DSAVE EQ�����~�s�b�Υ��b�M�����A�o�Ӫ��A�O���ජ�m���C\n");
		*/
		if( item->query_unique() )
			return notify_fail("�A���W���ߤ@�˳�[Unique EQ]�A����i�J[���m�Ҧ�]�C\n");
	}	

	me->set_inactive(1);
	write(@README
�A�N�ۤv�]�w��[���m�Ҧ�]�A�H�קK�o�b�Ӥ[�ӳQ�j�����u�C
[�`�N: ���Ҧ������i��Q�����A�п�ܦw�������m��m�C ]

README
);
	me->set_temp("cmds/inactive", 1);
	call_out("delay", 300, me);
	return 1;
}

void delay(object me)
{
	if( !me ) return;
	me->delete_temp("cmds/inactive");
}

void remove_call() { remove_call_out("delay"); }

int help(object me)
{
	write(@HELP
���O�榡�R inactive

�o�ӫ��O���A�]�w���u���m�Ҧ��v�A���Ҧ��N����@���Ͳz����C
�H�K���a�{�ɦ��Ʀӥ������}�@�q�ɶ��A�`�N���Ҧ������i��D�������C
���ϥΦ����O�ɬO���e�\��SAVE EQ�H�~���F���b���W�A�@�O����a
��only eq����idle�A�O�L�H���h�ϥΪ��v�Q�A�G�O������a�ϥΦ����O��
ROBOT�C
(�ثe�̤j���m�ɶ������p�ɡA�]�N�O300����)

HELP
        );
	return 1;
}

