// Room: /open/world1/tmr/xiangyang/eastjie1.c

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這是一條寬闊的青石板街道，向東西兩頭延伸。東邊是一
個大十字街口。西面是襄陽的中央廣場，北邊是襄陽守城大將
王堅的府邸大門，只見那兒守備森嚴，閑雜人等一般是不能接
近的。南面飄來一縷縷的藥香，噢，原來是一家藥鋪。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"eastjie1_w1",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"eastjie2_w1",
  "north" : __DIR__"jiangjungate",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -490,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
