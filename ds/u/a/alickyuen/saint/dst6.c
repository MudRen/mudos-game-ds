// Room: /u/a/alickyuen/area/dst6.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠East[2;37;0m");
	set("long", @LONG
這裡就近市中心，你感到很嘈吵。但是你看到前面有一個奇怪的現像，
就是前面聚集了一堆人群，你的好奇心教你想到那裡看看。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dmid.c",
  "east" : __DIR__"dst11.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
