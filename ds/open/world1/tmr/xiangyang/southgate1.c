// Room: /d/xiangyang/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "朱雀內門");
	set("long", 
"這裡是襄陽城的南城門的內城門，只見城門上方是三個大
字。"HIR"

                      朱雀門
\n"NOR
"近年來蒙古屢次侵犯襄陽城，故這兒把守相當嚴密，一些官兵
們正在盤查要離襄陽城的人。兩邊是上城頭的石階，向北進入
城區。\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"eastup" : __DIR__"walls2",
		"westup" : __DIR__"walls1",
		"south"  : __DIR__"southgate2",
		"north"  : __DIR__"southjie3",
	]));
	set("objects", ([
		__DIR__"task/pi3"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -500);
	set("coor/y", -550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
