// Room: /u/b/bennyng/area/room2.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊通道");
	set("long", @LONG
在十二黃金鬥士的畫像之後，你發現有一幅戰神雅典娜的油畫。裡面
的雅典娜正在和惡魔戰鬥著。你發現有一線陽光由北面的房間射到來，你
想可能那裡就是你的最後目的地，你就想踏步往前面去．．．．．．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */

  "north" : __DIR__"room1",
  "south" : __DIR__"room3",
]));
        create_door("north","木門","south",DOOR_CLOSED);
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
