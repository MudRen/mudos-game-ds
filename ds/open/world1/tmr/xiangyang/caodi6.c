// Room: /d/xiangyang/caodi3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��a");
	set("long", @LONG
�o�O�������~����a�C�X�j�L�i�ǥH�ӡA�o�̪��ʩm���i
���F�A���M�X�j�L�S�Ө�n���A���±��^�򵷲@����C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"southgate2",
//		"south"  : "/d/wudang/wdroad5",
	]));
	set("coor/x", -500);
	set("coor/y", -600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}