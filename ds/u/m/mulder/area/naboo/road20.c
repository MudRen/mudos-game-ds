// Room: /u/s/sonicct/area/road20.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這裡不是經常有居民通往，因為在東北的暗巷經常有一些流氓或做一
些非法活動，所以不是經常有一走到那裡。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
 "northeast" :__DIR__"road19",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
