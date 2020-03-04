// Room: /u/m/mulder/area/road14.c

inherit ROOM;

void create()
{
	set("short", "新彼得城警察局");
	set("long", @LONG
你看見這警察局周圍不是那麼繁榮，是本城的好事，因為這
表示沒有壞事發生，不是好嗎?
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
