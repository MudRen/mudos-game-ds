// Room: /u/t/tmr/area/street3.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
北邊有間打鐵店，店門口的招牌寫著「恨鐵不成鋼」，往東則是一條
沿著小溪的道路，不遠處有座森林，當地都為它取了一個名字，就叫「鬼
斷森林」，往南則是橫跨溪河的木橋。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wbridge",
  "west" : __DIR__"street2",
  "north" : __DIR__"smithy.c",
  "east" : __DIR__"river_road",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

set("light",1);
	setup();
	replace_program(ROOM);
}
