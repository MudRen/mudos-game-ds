// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
���O�榡�Runset <�ܼƦW>

�o�ӫ��O���A�R�������ܼƪ��]�w�C

�ק��ܼƳ]�w�Х� unset ���O�C
TEXT
	);
	return 1;
}
