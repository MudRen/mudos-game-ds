// ilist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("���O�榡�Rilist <������ɦW>\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) ob = find_object(resolve_path(me->query("cwd"), arg));
	if( !ob ) return notify_fail("�S���o�˪���γo�˪���S���Q���J�C\n");

	printf("%O�����ζ����~�ӥH�U�ɮסR\n    %s\n", ob,
		implode(deep_inherit_list(ob), "\n    "));
	return 1;
}

int help (object me)
{
        write(@HELP
���O�榡: ilist <������ɦW>
 
�C�X�@�Ӫ�����~�Ӫ��Ҧ�����C
 
HELP
);
        return 1;
}
 
