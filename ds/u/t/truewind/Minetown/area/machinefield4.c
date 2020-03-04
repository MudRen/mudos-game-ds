// Room: /u/t/truewind/Minetown/area/machinefield4.c

inherit ROOM;

void create()
{
	set("short", "漂浮車維修廠");
	set("long", @LONG
這裡是各類漂浮車維修的工廠，放眼望去，各式各樣的漂浮車堆
的跟山一樣高，幾乎要遮蔽了你的視線。這裡有許多舊式的改裝型漂
浮車，像是1996年的可樂娜還有賓士，真是舊的可以了。附近還有一
些令你非常眼熟的改裝車。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"machinefield5",
  "east" : __DIR__"machinefield1",
]));

	setup();
	replace_program(ROOM);
}
