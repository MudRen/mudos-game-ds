#include <path.h>
inherit ROOM;
void create()
{
	set("short", "黑色小道路");
	set("long", @LONG
你正走在一條黑色的小道路上，周圍的風景黑漆漆的，連在白天都
會被參天的大樹木給遮住陽光，在西北方有一條諾大的山路，大概就是
傳說的天山吧！往西南邊是一個熱鬧的城鎮。
LONG
	);
	set("exits", ([
  "enter" : __DIR__"temproom.c",
//  "northwest" : ACME_PAST+"area/pass6.c",
  "northeast" : __DIR__"outroad4.c",
  "southwest" : TMR_PAST+"area/city-door.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
