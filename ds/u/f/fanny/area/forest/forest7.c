// Room: /u/f/fanny/area/forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
剛剛那條山徑只有延伸到這裡，看來樵夫們最深入的地方也不過
到這兒而已。南邊不遠的地方有個小亭子，累了的話可以到那裡休息
休息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest8",
  "west" : __DIR__"forest6",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
