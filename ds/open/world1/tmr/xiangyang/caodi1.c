// Room: /d/xiangyang/caodi1.c
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
		"west"    : __DIR__"northgate2",
	//	"northup" : "/d/jueqinggu/dufengling",
	]));
	set("objects", ([
		__DIR__"npc/tuolei"   : 1,
		__DIR__"npc/menggubing" : 2,
	]));
	set("coor/x", -490);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
