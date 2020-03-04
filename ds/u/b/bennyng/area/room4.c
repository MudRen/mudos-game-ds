// Room: /u/b/bennyng/area/room4.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "教皇大殿");
	set("long", @LONG
這裡是十二官後的教皇大殿，四處非常宏偉，中間有一張大椅，
是教皇專用的．這裡是教皇處理日常事務的地方，非請勿進．往北是
教皇所住的地方．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room5",
  "north" : __DIR__"room3",
]));
       create_door("south", "大殿之門", "north", DOOR_CLOSED);
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
