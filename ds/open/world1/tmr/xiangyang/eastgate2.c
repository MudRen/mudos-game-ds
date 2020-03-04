// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "青龍外門");
	set("long", 
"這裡是襄陽城的東城門，只見城門上方是三個大字。"HIG"

                      青龍門
\n"NOR
"近年來蒙古屢次侵犯襄陽城，故這兒把守相當嚴密，一些官兵
們正在盤查要離襄陽城的人。兩邊是很大的草地。\n"
 );
	set("exits", ([
		"west"  : __DIR__"eastgate1",
//		"east"  : "/d/jianzhong/shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -440);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}