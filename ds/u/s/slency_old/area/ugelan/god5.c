// Room: /u/s/slency/area/ugelan/god5.c

inherit ROOM;

void create()
{
	set("short", "墓園");
	set("long", @LONG
這裡是較偏森林的墓地, 有些墳墓甚至快到森林裡頭去了, 這裡有
些墓碑旁的泥土十分泥濘, 看來不久前才有人動過, 不過看墓碑的年代
, 似乎也不是因為剛埋葬的關係....。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"god6",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
