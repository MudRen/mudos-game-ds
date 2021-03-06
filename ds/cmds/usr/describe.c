// describe.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("指令格式﹕describe <描述>\n");
	if( arg == "none" )
	{
	 me->delete("long");
	 write("刪除OK!\n");
	 return 1;
	}
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("請將您對自己的描述控制在八行以內。\n");

	arg = implode(txt, "\n") + "\n";

	me->set("long", arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式﹕describe <描述>

取消用 describe none

這個指令讓你設定當別人用 look 指令看你時﹐對你的描述﹐通常當你
的描述超過一行時可以用 to describe 的方式來輸入。
TEXT
	);
	return 1;
}
