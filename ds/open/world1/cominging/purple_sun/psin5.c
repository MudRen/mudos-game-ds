inherit ROOM;

void create()
{
	set("short", "山腳旁");
	set("long", @LONG
在這裡是紫陽山下的山腳旁，在這裡有幾戶人家，也有一條小小細
細的小河流流過，在河邊還有一些婦女在洗滌衣物，拿著東西勤奮洗著
。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin6.c",
  "east" : __DIR__"psin4.c",
    "west" : "/open/world1/moonhide/area/hotel",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
