// �p�^�Ԩ�

#include <ansi.h>

inherit VEHICLE;

void create()
{
	set_name(HIG"�p�^�Ԩ�"NOR,({"power tank","power","tank"}));
	// �q�~���ݹp�^�Ԩ����ԭz
	set("vlong",@LONG
�o�x�p�^�Ԩ��O�����Ū��ѩҬ�o�������A���㦳���į�H�ΰ����O���S�ʡC
�z����...............
LONG
	);
    set("short", HIC"�p�^�Ԩ��r�p�y"NOR);  // �Ԩ��̪��u�ԭz
	// �Ԩ��̪����ԭz
	set("long", @LONG
	�~�w�w�w�w�w�w�w���~�w�w�w�w�w�w�w���~�w�w�w�w�w�w�w��
	�x Searching... �x�x      �s      �x�x              �x
	�x              �x�x              �x�x             2�x
	�x              �x�x�u    �q    �t�x�x            19�x
	�x              �x�x              �x�x   -----+-----�x
	�x              �x�x      �r      �x�x   0123456789A�x
	���w�w�w�w�w�w�w�����w�w�w�w�w�w�w�����w�w�w�w�w�w�w��
	  �o�̦��ƭӺʱ��ù��A�L�ɵL��a�ʱ��۹p�^�Ԩ��a�|�P�C
LONG
	);
	set("exits", ([ /* sizeof() == 0 */
            ]));
            
	set_max_capacity(9999999999);
	set_max_encumbrance(900000099);
	set_weight(999999999);
	set("valid_startroom", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�x");
		set("value", 99999999);
	}
	setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_leave","leave");
	add_action("do_lookout","vlook");
	add_action("do_vgo","vgo");
}

int do_enter()
{
	object me;
	object env;
	me = this_player();
	if(!enter_vehicle(me))
		write("�����o...\n");
	else
		write("Ya!!!���\\�F...\n");

	return 1;
}

int do_leave()
{
	object me;
	object env;
	me = this_player();
	if(!leave_vehicle(me))
		write("�����o...\n");
	else
		write("Ya!!!���\\�F...\n");

	return 1;
}

int do_lookout(string arg)
{
	string line;
	line = look_out(arg);
	return 1;
}

int do_vgo(string arg)
{
	v_go(arg);
	return 1;
}

