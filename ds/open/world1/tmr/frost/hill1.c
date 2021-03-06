// Room: /open/world1/tmr/frost/hill1.c

inherit ROOM;

void create()
{
	set("short", "倚霄山-山腰小徑");
	set("long", @LONG
倚霄山地勢雖高，號稱倚霄卻四季如春，終年難見一片雪花。這條位
在半山腰的道路，往西邊可以通往接向凌雲峰的棧道，往東不遠處是一座
造勢宏偉的道觀，往東北方的林道可接往一處觀景台。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"observatory",
  "west" : __DIR__"footway3",
  "east" : __DIR__"temple",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
