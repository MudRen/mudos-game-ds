// describe.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("���O�榡�Rdescribe <�y�z>\n");
	if( arg == "none" )
	{
	 me->delete("long");
	 write("�R��OK!\n");
	 return 1;
	}
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("�бN�z��ۤv���y�z����b�K��H���C\n");

	arg = implode(txt, "\n") + "\n";

	me->set("long", arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
���O�榡�Rdescribe <�y�z>

������ describe none

�o�ӫ��O���A�]�w��O�H�� look ���O�ݧA�ɡM��A���y�z�M�q�`��A
���y�z�W�L�@��ɥi�H�� to describe ���覡�ӿ�J�C
TEXT
	);
	return 1;
}
