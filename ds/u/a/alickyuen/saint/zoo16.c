// Room: /u/a/alickyuen/area/zoo16.c
//updated by alickyuen 9/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Secret＠CyberZoo"NOR);
	set("long", @LONG
在這裡草叢實在太高跟本看不清楚東西南北令你心情焦急，希望盡早
出去。走著走著，你不禁有些心慌了。你的直覺告訴你，尋找出路是現在
你應該做的事。
LONG
	);
	set("exits", ([ /* sizeof() == 8 */
  "northwest" : __DIR__"zoo13",
"southwest":__DIR__"zoo13",
"north":__DIR__"zoo13",
"south":__DIR__"zoo13",
"southeast":__DIR__"zoo13",
"northeast":__DIR__"zoo17",
"east":__DIR__"zoo13",
"west":__DIR__"zoo13",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
