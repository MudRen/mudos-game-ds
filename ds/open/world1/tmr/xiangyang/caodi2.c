// Room: /d/xiangyang/caodi2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��a");
	set("long", @LONG
�o�O�������~����a�C�X�j�L�i�ǥH�ӡA�o�̪��ʩm���i
���F�A�X�j�L�����ӥh�A�H�������A�Фg�����A�ƬO�۱i�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"npc/menggubing" : 2,
	]));
	set("coor/x", -510);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}