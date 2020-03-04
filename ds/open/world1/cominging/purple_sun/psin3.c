inherit ROOM;

void create()
{
	set("short", "山旁森林");
	set("long", @LONG
這裡是森林中的一角，在周圍有著一條條的小蛇，是周圍人家所飼
養的，不知道什麼原因都跑到森林中來迷走，這裡大部份都是一些竹林
與北方似乎不大相同。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin2.c",
  "northwest" : __DIR__"psin4.c",
//      "west" : "open/world1/moonhide/area/room1", // 舊古墓
      "west" : "/open/world1/tmr/gumu/shulin1",// 新古墓 Tmr 2006/10/23
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
