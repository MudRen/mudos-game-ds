// Room: /u/s/slency/area/ugelan/church7.c

inherit ROOM;

void create()
{
	set("short", "護城河畔小徑");
	set("long", @LONG
這裡是一條延著護城河河畔的小徑，這裡的路面雜草叢生，看來已
鮮有旅客會到此遊玩，繼續往東北走則是一座森林，往南通往較多人群
的步道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"church8",
  "south" : __DIR__"church6",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
