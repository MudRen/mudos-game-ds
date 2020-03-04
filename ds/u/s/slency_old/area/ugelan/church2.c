// Room: /u/s/slency/area/ugelan/church2.c

inherit ROOM;

void create()
{
	set("short", "長型廣場");
	set("long", @LONG
這裡是一座相當大的廣場，廣場上的路人並不很多，倒是鴿子滿處
聚集在一起，啄食著旅客們餵食的食物，由此往西可以回到城中心，往
東不遠處有座高聳的教堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church1",
  "east" : __DIR__"church3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
