// huangshalin.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "���F��");
	set("long", @LONG
���B���׫n�s�賡�C�u�����B������W�A�t�ߵۤ@�y�ѯ�F��n
�Ӧ����s���A�i�����_�S�C�ڷ�a�H���A�o�O�b�Ӵ¡A�@��W�s���ȥP
���H�A�Ϊk�O���Ӥ@�Ѷ��F�Ӧ��C���F�O�@���K�L�C
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"east" : __DIR__"mumen",
	]));
	setup();
	replace_program(ROOM);
}
