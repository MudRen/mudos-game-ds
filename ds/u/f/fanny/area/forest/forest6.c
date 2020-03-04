// Room: /u/f/fanny/area/forest/forest6.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
到了這，那股怪力量及令人不寒而慄的肅殺之氣已消失殆盡，而
樹林裡也可以看到那些覓食中的小動物，看來已經走出了那個令人心
生不快的範圍了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"forest5",
  "east" : __DIR__"forest7",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
