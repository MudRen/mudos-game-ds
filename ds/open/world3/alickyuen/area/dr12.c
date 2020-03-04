// Room: /u/a/alickyuen/area/dr12.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Liftdoor");
	set("long", @LONG
這�堿O三樓北部的走廊，人流密集，是傳送機的入口，你能夠使用傳
送機來往醫院各層或一些重要地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr15",
  "enter" : __DIR__"dr10",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
