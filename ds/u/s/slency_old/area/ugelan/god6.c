// Room: /u/s/slency/area/ugelan/god6.c

inherit ROOM;

void create()
{
	set("short", "墓園");
	set("long", @LONG
此地的墓地都十分整齊, 看來是有專人在整理的關係, 雜草也都有
人除過, 應該都是城裡的居民輪流來清理的吧, 否則光靠教堂裡面的人
員是不可能做到的, 往東南走便快進入一座森林了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"god4",
  "southeast" : __DIR__"god5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
