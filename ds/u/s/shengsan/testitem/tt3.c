#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"�ŤѴ��ջ�(�C���ɶ�)"NOR,({"tt3"}));
	set("long","�o�O�@�Ӥ��Ŵ��ջ��C\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_tt3","tt3");
}

int do_tt3()
{
	object me;
	me = this_player();

	message("world:world1:vision","�j�N�Ǥ��~(�Ҧ�����)�T������!!!!\n",users());
	message("world:world2:vision","�{�N�Ǥ��~(�Ҧ�����)�T������!!!!\n",users());
	message("world:world3:vision","���ӫǤ��~(�Ҧ�����)�T������!!!!\n",users());
	message("world:world1:outdoor:vision","�j�N�ǥ~(���~)�T������!!!!\n",users());
	message("world:world2:outdoor:vision","�{�N�ǥ~(���~)�T������!!!!\n",users());
	message("world:world3:outdoor:vision","���ӫǥ~(���~)�T������!!!!\n",users());
	

	return 1;
}
