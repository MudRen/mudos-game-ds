// Room: /u/s/superbug/train/r-10.c

inherit ROOM;

void create()
{
	set("short", "鐵路");
	set("long", @LONG
你忽然停下了腳步，直覺告訴你面前似乎沒有路可走了，你伸手一摸
，原來前面的地面崩塌了，只剩下鐵軌仍相連著，也許你需要找個交通工
具才能通過，目前你只好沿著鐵軌往回走。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r-9.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
