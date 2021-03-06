// Room: /d/xiangyang/westgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "白虎內門");
	set("long", 
"這裡是襄陽城的西城門的內城門，只見城門上方是三個大
字。"HIW"

                      白虎門
\n"NOR
"近年來蒙古屢次侵犯襄陽城，故這兒把守相當嚴密，一些官兵
們正在盤查要離襄陽城的人。兩邊是上城頭的石階，向東進入
城區。\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"    : __DIR__"westjie3",
		"west"    : __DIR__"westgate2",
	]));
	set("objects", ([
		__DIR__"task/pi4"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -550);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
