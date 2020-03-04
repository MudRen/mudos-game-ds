// Room: /u/a/alickyuen/area/dr27.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
你來到了醫院三樓的南邊，這邊走廊是通往一些工作室和休息室。你
看見你右邊的房間門上寫著醫生休息室的牌子亮著。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dr16",
  "south" : __DIR__"dr28",
  "enter" : __DIR__"dr30",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
