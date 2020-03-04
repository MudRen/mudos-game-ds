// Room: /u/s/sonicct/area/road18.c

inherit ROOM;

void create()
{
	set("short", "Naboo廣場");
	set("long", @LONG
這是通往廣場的唯一通道，由於Naboo城的人全部是和平主義
者，所以茶餘飯後的時間大多數人都會走到廣場談天說地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shop7",
  "south" : __DIR__"road8",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
