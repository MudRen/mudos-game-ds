// Written By Alickyuen@ds 30 April 2005

#include <ansi2.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write(""+CLR);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式： cls

這個指令可以清除畫面。
HELP);

	return 1;
}
