#include <path.h>
inherit ROOM;

void create()
{
	set("short", "山旁森林");
	set("long", @LONG
這裡是一座城旁的森林，在森林所圍繞之地是傳說中疾風門的祖地
，在附近有著許多縱行之生物，也有一些在你的身旁環繞著，森林之中
光亮微弱，白天陽光小時幾乎需要用到火把來照亮行走。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"psin2.c",
  "east" : COMINGING_PAST + "area/river7.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
