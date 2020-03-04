// Room: /u/d/darkfool/area1/32.c

inherit ROOM;

void create()
{
	set("short", "街道轉角");
	set("long", @LONG
你的南方有條小小的岔路，有幢建築物隱隱約約的在路的盡頭，
主要道路繼續向著東面，這裡的居民看來比較少一些，有種較為冷清
的感覺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"33",
  "west" : __DIR__"31",
  "south" : __DIR__"l1",
]));

	setup();
	replace_program(ROOM);
}
