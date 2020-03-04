// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
一條用青石鋪成的街道，到處可見不少的小販在此販賣雜物，居民
們也大都喜歡來此購物，便宜且種類繁多是此賣場的特色，往西是一條
頗長的街道。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road3",
  "north" : __DIR__"road7",
]));
 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
