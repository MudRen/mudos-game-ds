// Room: /d/xiangyang/caodi4.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "草地");
	set("long", @LONG
這是襄陽城外的草地。蒙古兵進犯以來，這裡的百姓全進
城了，這裡幾十里都沒了人煙。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"southgate2",
	]));
	set("coor/x", -490);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}