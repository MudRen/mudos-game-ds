// �٧Q�l shelizi.c

#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("�C��٧Q�l", ({ "shelizi pill","pill" }));
        set("long",@LONG
�@�����o�ۤC�m���~���٧Q�l�A�������J��j�p�A�����z�A�~���
�ƵL��ү�A���b��̧Y�Pı�����H���몺�_���P���A��H�@�b���y���q��
�A�D�k�o�k�C
LONG
	);
        set_weight(50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	        set("unit", "��");
		set("eat_msg",HIC"$N�Y�U�@�����o�C�m���~���ĤY�C"NOR);
	        set("eff_msg",HIY "�@�}�O�Ԫ����~�}�lŢ�n�ۧA�A�կ`�T�_�@�}��....\n" 
						+ NOR CYN "(�A���W���˶ճ���_�F�I�I)" NOR );
	}
	set("value", 5000);
	set("cure",([
		"body" : 50,
		"head" : 50,
		"left_leg" : 10,
		"right_leg" : 10,
		"left_arm" : 10,
		"right_arm" : 10,
	]));
	set("heal",([
		"hp"	: 300,
		"mp"	: 300,
		"ap"	: 300,
	]));
    setup();
}
