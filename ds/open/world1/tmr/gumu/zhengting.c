// zhengting.c ���U
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���U");
	set("long", @LONG
�o���O�j�Ӫ����U�A�������Ӱ����F�^�ä줧�����F��A�o�����D
�Q�H�������h�F�C�U�������\�ۤ@�i�j�۴ȡA�U���W�\��ۤ@�ǥ��Y
�������o�@�A�����O�@�i�j�ۮ�C
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao15",
		"east"  : __DIR__"mudao14",
		"north" : __DIR__"mudao11",
		"south" : __DIR__"mudao16",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

