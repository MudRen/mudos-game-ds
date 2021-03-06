// Room: /u/t/tmr/area/vroad1.c
#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "孟村街道");
	set("long", @LONG
你正走在孟村的街道，只見屋舍儼然，溝渠齊整，感受得出來孟村的
管理井井有條。往東為出孟村的道路，往西可看到一個小廣場，南邊有間
小屋，只見其屋門上畫著七株精雅的紫色梅花。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"menghouse",
  "west" : __DIR__"vroad2",
  "east" : __DIR__"ms4",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
create_door("south","木板門","north",DOOR_CLOSED);
}
