//updated by alickyuen130/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
這裡是一間商店的入口，但同時也是水族館的入口。如果你想買東西
的話就可到商店，你也可以到上層的水族館看看。聽說這水族館的魚的種
類很多，而每天都好像會有魚類表演的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"zoo9",
  "east" : __DIR__"zoo3",
  "enter" : __DIR__"zoo8",
]));
set("objects", ([
__DIR__"npc/zooer.c" :1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
