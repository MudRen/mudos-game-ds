// Room: /d/xiangyang/caodi5.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��a");
	set("long", @LONG
�o�O�������~����a�C�X�j�L�i�ǥH�ӡA�o�̪��ʩm���i
���F�A�o�̴X�Q�����S�F�H�ϡC
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"southgate2",
	]));
	set("coor/x", -510);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

