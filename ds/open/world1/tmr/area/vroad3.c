// Room: /u/t/tmr/area/vroad3.c
#include <path.h>

inherit ROOM;

void create()
{
	set("short", "孟村道路");
	set("long", @LONG
你正走在一條道路上，往東可到達一片廣場，在你北邊是座小廟，只
見不少人進出，看得出來此間廟宇香火倒頗興旺。往南有條小河，算是本
村最重要的一條河。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : WD_PAST+"sand/room1",
  "north" : __DIR__"fane",
  "east" : __DIR__"vroad2",
  "southwest" : __DIR__"m_river",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
