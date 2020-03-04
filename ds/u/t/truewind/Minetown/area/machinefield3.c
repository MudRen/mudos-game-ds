// Room: /u/t/truewind/Minetown/area/machinefield3.c

inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。這裡擺了很多透明的大桶子
，桶子底部延伸出幾條管線往北方連結過去，似乎跟重力壓縮機有點
關係。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"machinefield6",
  "north" : __DIR__"machinefield2",
]));

	setup();
	replace_program(ROOM);
}
