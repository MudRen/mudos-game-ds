// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	if( !arg ) arg = user_path(me->query("id"));
	if( strsrch(arg, "...") >= 0 ) return notify_fail("�S���o�ӥؿ��C\n");	//Add by Luky
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail("�S���o�ӥؿ��C\n");

	if(dir[strlen(dir)-1]!='/') dir += "/";
	me->set("cwd", dir);
	write(dir + "\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
���O�榡 : cd <�l�ؿ��W>, cd .. , and cd

�N�ثe�ѦҪ��ؿ����ܫ��w���l�ؿ��Φ^��W�@�D�ؿ�; ��i�����^��ۤv�u�@�ؿ��C
HELP
	);
	return 1;
}
