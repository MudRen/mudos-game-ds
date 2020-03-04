// Room: /u/t/truewind/Minetown/area/minetown8.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這是礦村中的一塊空地，地上有幾根冒出的管線，不過看起來怪
怪的，管線上正冒著火花。往西走是附近最大的各式車輛維修廠，往
南則是管理整個礦村的礦村長"怪手"威廉的住處。往東邊去可以獲得
一般物資的補充。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","land");
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown7",
  "west" : __DIR__"machinefield1",
  "east" : __DIR__"minetown5",
  "south" : __DIR__"minetown9",
]));

	setup();
	replace_program(ROOM);
}
