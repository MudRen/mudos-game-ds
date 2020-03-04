// Room: /u/s/slency/area/ugelan/church5.c

inherit ROOM;

void create()
{
	set("short", "護城河畔小徑");
	set("long", @LONG
這裡是一條延著護城河河畔的小徑，此地風光明媚，是旅遊休憩的
好地點，眼前不是青草，便是綠水，充滿了無限詩情畫意，往北是一條
小徑，往南通往城中心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"church6",
  "south" : __DIR__"church1",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
