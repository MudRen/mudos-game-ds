// Room: /open/world1/tmr/dragoncity/north1.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
這是一條寬闊的青石街道，向南北兩頭延伸。北面是玄武
內門，南邊顯得很繁忙。西邊是一間茶館，一面招幡上用朱砂
書著茶字，正在風中輕輕地搖曳著，一股股茶香撲面而來。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"north_din",
  "north" : __DIR__"northgate1",
  "west" : __DIR__"hotel",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
