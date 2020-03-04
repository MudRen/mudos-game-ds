// Room: /u/f/fanny/area/forest/forest2.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
更深入森林，根據你闖蕩多年的經驗，這兒看起來到還真是你想
的那麼一回事，依稀可以感覺出那那肅殺之氣，不過這地方卻還有另
外一股莫名的壓力。往南走是一條樵夫經年累月砍柴走出的山徑，北
邊看樣子是一條野獸出末的小徑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"forest5.c",
  "west" : __DIR__"forest1.c",
  "north" : __DIR__"forest3.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
