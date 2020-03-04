// Room: /u/t/truewind/Minetown/area/machinefield1.c

inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。這裡的管理者除了維修以外
也提供漂浮車及各類二手買賣的服務，如果你有需要賣掉的東西也可
以來這裡找買主。
LONG
	);
	set("objects", ([ 
        __DIR__"npc/machinedealer.c" :1 ,
]));
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield2",
  "east" : __DIR__"minetown8",
]));

	setup();
}
