// Room: /open/world1/tmr/north_bar/town1.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-村口");
	set("long", @LONG
來到這裡，往前一望，有一個大大的用竹子做的大門，裡面
似乎是個部落。住家房子的屋頂有的用大圓木搭建，但也有只使
用稻草堆搭成的普通民房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/world1/whoami/birdarea/en76",
  "north" : __DIR__"town2",
]));
	set("outdoors", "land");
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
