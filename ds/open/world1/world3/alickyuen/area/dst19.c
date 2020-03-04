// updated /open/world3/alickyuen/area/dst19
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠West"NOR);
	set("long", @LONG
到最後，你還是跟蹤人群來看看，原來在這裡的不遠處是一間旅行社
。很多人在排隊登記去旅行，使這裡變得人來人往。另外，北面也有一間
郵局，你可以到那裡使用郵政服務。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"post",  //加出口
  "east" : __DIR__"gate4",
]));

        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));

   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
