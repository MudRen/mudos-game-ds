// Luky @DS 1999.9.2
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("�ڤۼ���",({"lottery ticket","lottery","ticket","price_ticket"}) );
	set("long",@LONG
�@�i10*20�������m���A�W���L�F�@�T����ϮסC
�I���٦L�F�@�ǹ����k:

	���m���N�w�ɶ}���A�ñN�������X�P�B�Z�n��ڤۤ�����A 
	�Ф����H�ܪ���������������C
LONG
);
        set_weight(1);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","�i");   //luky
	}
         set("value", 500);
      set("no_sell", 1);
	setup();
	set("volume",1);
}

string short()
{
	string str;
	if(query("time")) str=sprintf("�ڤ۱m��(Lottery ticket) [��%d��]",query("time") );
	else str="�ڤ۱m��(Lottery ticket)";
        return str;
}

string long()
{
	string str;
	str=sprintf("%s\n"HIW"�o�O�@�i��%d�����m���A�W�������X�O: %d\n"NOR,query("long"),query("time"),query("number"));
	return str;
}

int is_ticket()
{
	return 1;
}
