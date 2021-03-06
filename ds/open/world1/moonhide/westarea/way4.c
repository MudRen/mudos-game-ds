// Room: /open/world1/moonhide/westarea/way4.c

inherit ROOM;

void create()
{
	set("short", "雲端-中央通道");
	set("long", @LONG
你正在雲海上的走道，腳下踩的是團團白花花的雲朵，你也不清
楚人怎麼可能站在雲上，這的確是個不解之迷。這裡是處十字路口，
雲路往四面八方伸展而去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"way3.c",
  "south" : __DIR__"way5.c",
  "east" : __DIR__"hall2",
  "west" : __DIR__"hall1.c",
    "down" : __DIR__"way4d.c",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
