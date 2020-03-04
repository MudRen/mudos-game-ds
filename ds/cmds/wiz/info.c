// info.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object obj;
	string str;

	if (!arg) return help(me);

	seteuid(geteuid(me));

	if( arg=="me" ) obj = me;
	else if( arg=="my link" ) obj = me->query_temp("link_ob");
	else {
		obj = present(arg, me);
		if (!obj) obj = present(arg, environment(me));
		if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
		if (!obj) return notify_fail("�S���o�˪���....�C\n");
	}

	printf("���� [%O]\n-----------------------------------------------------\n", obj);
	write("�ɮסR\t\t" + base_name(obj) + ".c\n");
	write("���R\t\t" + domain_file(base_name(obj)) + "\n");
	write("�@�̡R\t\t" + author_file(base_name(obj)) + "\n");
	write("�v���R\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("���šR\t\t" + wizhood(obj) + "\n");
	write("�ϥΰO����R\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "�ͪ� ";
	if( userp(obj) )		str += "�ϥΪ� ";
	if( interactive(obj) )	str += "�u�W ";
	if( wizardp(obj) ) 		str += "�Ův ";
	if( clonep(obj) ) 		str += "�ƻs ";
	if( virtualp(obj) ) 	str += "���� ";
	if( query_heart_beat(obj) ) str += "�߸�:" + query_heart_beat(obj) + " ";
	write("�ݩʡR\t\t" + str + "\n");
	write("�ƻs�ӼơR\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("�Ѧҳs���R\t" + refs(obj) + "\n");

	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : info <���󤧦W�٩��ɦW>

�Q�Φ��@���O�i�o���@�Ǧ����Ӫ��󪺸�T�C
HELP
    );
    return 1;
}
