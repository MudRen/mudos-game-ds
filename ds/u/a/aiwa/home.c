// Room: /u/a/aiwa/room/home.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIG+"��ؤu�@��"+NOR);
	set("long", @LONG
�u�O�O�H��Y�I�b�o��@�Ӥ��_�����p�θ̡A�~�M���p�����i �H
���]�ơA�Ҧ��~�a�ͬ��Ϋ~���������I�A�ݨ즳�ӤH�����b�q��
�e�E��|�����ާ@�۹q���A �٬O���n�h���Z�L�n�F�I 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"out" : "/u/a/aiwa/workroom",
            ]));

	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me=this_player();
	add_action("do_out","out");
	if(me->query("id")!="aiwa")
		tell_object(me,"\n"HIW+"�Y�H(Somebody)�i�D�A: ���n���Z�L�g�{����!!\n");
}

void do_out()
{
	object me;

	me = this_player();
	tell_object(me,"\n\n[1;37m���¥��{��ؤu�@��\n\n");
	tell_object(me,"���ŦA�ӧ���I[m\n\n\n");
}