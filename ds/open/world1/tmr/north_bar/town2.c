// Room: /open/world1/tmr/north_bar/town2.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-村口");
	set("long", @LONG
當你的腳踏進大門時，深吸一口氣，精神突然好了起來，這
裡的空氣真是新鮮。你四處張望，發覺這裡的人十分的活潑好動
，待客也十分熱情，這兒人們所穿服飾，也都跟你生平所見的完
全不一樣。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town1",
  "north" : __DIR__"town3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
