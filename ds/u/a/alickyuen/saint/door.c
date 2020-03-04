// update 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠East"NOR);
	set("long", @LONG
來到這裡，你已經看到一個大大的牌子寫著『動物園』三個字，牌的
四處放滿了五顏六色的小燈泡。在早上也十分美麗，在晚上更是另人目不
暇給。往東便可以到達動物園的入口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst13.c",
  "east" : __DIR__"enter",
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
