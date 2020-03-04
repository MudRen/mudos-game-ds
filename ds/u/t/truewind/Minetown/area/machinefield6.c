// Room: /u/t/truewind/Minetown/area/machinefield6.c

inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。這裡擺了一個大鐵箱，旁邊
堆滿了齒輪跟引擎還有各式各樣的零件，你仔細的四處張望，居然還
有企業號用的曲速引擎，不過大概不能用了。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"machinefield5",
  "east" : __DIR__"machinefield3",
]));

	setup();
	replace_program(ROOM);
}
