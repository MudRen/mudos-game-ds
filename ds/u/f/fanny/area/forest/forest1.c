// Room: /u/f/fanny/area/forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
這裡是一片茂密的松樹林，寧靜中卻似乎暗藏著殺機，看似生機
勃勃的樹林，竟看不到任何一隻活動中的野獸，看起來真有一種說不
出的詭異。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"forest2.c",
]));

	setup();
	replace_program(ROOM);
}
