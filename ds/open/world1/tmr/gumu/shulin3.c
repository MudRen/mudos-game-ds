// Room: /open/world1/tmr/gumu/shulin3.c

inherit ROOM;

void create()
{
	set("short", "小樹林");
	set("long", @LONG
這里是樹林的邊緣，參天古樹已經很稀少了。東面有一座高山，隱
約看見山間云霧繚繞中，似乎有什么廊檐的建筑。山勢緩和，但山上郁
郁蔥蔥地栽滿了樹木。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"caodi",
  "west" : "/open/world1/moonhide/area/room1",
  "northeast" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}
