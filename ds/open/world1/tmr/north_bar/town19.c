// Room: /open/world1/tmr/north_bar/town19.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－藥鋪");
	set("long", @LONG
這裡是村裡唯一的一家藥店，遠遠就可聞到濃濃的藥草味
藥鋪大夫就坐在前面磨著藥粉。
LONG
	);
	set("light", 1);
	set("objects", ([ 
	__DIR__"npc/herbalist" : 1, ]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"town18",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
