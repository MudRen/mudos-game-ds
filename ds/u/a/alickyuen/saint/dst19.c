// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠West"NOR);
	set("long", @LONG
到最後，你還是跟蹤人群來看看，原來在這裡的不遠處是一間旅行社
。很多人在排隊登記去旅行，使這裡變得人來人往，另你有點兒想去和人
們一起排隊報名參加這次的大旅行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  // "west" : "/u/s/steps/area/py/gate1",
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
