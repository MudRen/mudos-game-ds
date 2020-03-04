// Room: /u/d/darkfool/area1/16.c

inherit ROOM;

void create()
{
	set("short", "北住宅區街道");
	set("long", @LONG
這裡是鎮北面的住宅區，街道兩邊全是由速成屋構成的住家，幾
個居民並肩愉快地從你面前經過，他們的手上拿著採礦工具，看來是
準備要到礦坑去上工，南邊有間比較豪華的速成屋，看來不是普通的
礦工人家。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"17",
  "west" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}
