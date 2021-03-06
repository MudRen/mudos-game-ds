// Room: /u/t/truewind/Minetown/area/minetown7.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這裡是礦村邊緣的一塊空地，一道包圍礦村的牆往南延伸而去。
附近堆了一些廢棄的機件。北方傳來空中車輛起降的引擎聲，幾輛地
勤運輸車正經過此地，準備把貨物運到遠地去。
LONG
	);
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"plane-room",
  "east" : __DIR__"minetown6",
  "south" : __DIR__"minetown8",
]));
	set("no_clean_up", 0);
	set("current_light", 0);

	setup();
	replace_program(ROOM);
}
