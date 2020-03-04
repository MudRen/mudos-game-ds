// Room: /u/m/mulder/area/shop2.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 街道");
	set("long", @LONG
你開始一步一步向前行，而你的心情也開始變得緊張，因為
這是許多人說的「時空殺手」所在地．據說有很多無知的人走進
來從此也不見了，而警察局也派人進來找尋失蹤的人，但出回來
的人都忘記了發生什麼事，十分神秘．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road13",
  "south" : __DIR__"road6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
